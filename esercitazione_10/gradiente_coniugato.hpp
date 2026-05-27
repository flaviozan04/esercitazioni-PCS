#include <iostream>
#include "Eigen/Dense"
#include "Eigen/SVD"

int GradConiugato(unsigned int n) 
{
  const double tol = 1.0e-15;

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

  if (abs(B.determinant()) < tol)
    return -1;

  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_ex;

  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd res = b - A * x;
  double res_norm_0 = res.norm();
  Eigen::VectorXd p = res;

  const unsigned int it_max = 10000;
  unsigned int it = 0;
  const double res_tol = 1.0e-12;

  while (it < it_max && res.norm() > res_tol * res_norm_0){

    const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();

    x = x + alpha_k * p;
    res = b - A * x;

    const double beta = ((p.transpose() * A * res)/(p.transpose() * A * p)).value();
    p = res - beta * p;

    it++;
  }

  const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() : (x - x_ex).norm() / x_ex.norm();
  
  if (err_rel > 1.0e-6){
    return -1;
  }else{
    return 0;
  }

}