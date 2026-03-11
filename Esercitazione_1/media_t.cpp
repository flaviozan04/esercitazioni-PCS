#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	double temp_tot;
	double divisore=4.0;
	string location;
	string filename = "input_es1.txt";
	ifstream ifs(filename);
	if ( ifs.is_open() ) {
		while (ifs >> location) {
			double temp;
			 temp_tot=0;
			for (int i=0; i<4; i++){
				ifs >> temp;
				temp_tot+=temp;
			
			}
			temp_tot=temp_tot/divisore;
			cout << "avg. Temperature at " << location << " is " << temp_tot << "\n";
		}
	}
	return 0;
}
