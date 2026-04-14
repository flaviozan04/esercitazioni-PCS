dimensioni = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

bubble_sort = [4.14e-07, 6.53e-07, 1.761e-06, 5.864e-06, 2.2773e-05, 9.4596e-05, 0.00057712, 0.00144048, 0.0049157, 0.0196695, 0.0850916, 0.364897];

selection_sort = [2.94e-07, 5.11e-07, 1.414e-06, 4.477e-06, 1.2674e-05, 6.7261e-05, 0.000242269, 0.000647262, 0.00215168, 0.00840023, 0.0351035, 0.135208];

insertion_sort = [2e-07, 3.46e-07, 7.45e-07, 1.861e-06, 6.325e-06, 2.0824e-05, 9.0536e-05, 0.000330973, 0.00111576, 0.00488222, 0.0185788, 0.0740153];

std_sort = [6.5e-07, 6.17e-07, 1.402e-06, 3.791e-06, 7.031e-06, 1.5258e-05, 5.6835e-05, 8.3389e-05, 0.000135039, 0.000324933, 0.000645915, 0.00137094];

figure
plot(dimensioni, bubble_sort, '-o', 'LineWidth', 1.5); 
hold on
plot(dimensioni, selection_sort, '-s', 'LineWidth', 1.5);
hold on
plot(dimensioni, insertion_sort, '-^', 'LineWidth', 1.5);
hold on
plot(dimensioni, std_sort, '-d', 'LineWidth', 1.5);

xlabel('Dimensione del Vettore');
ylabel('Tempo (secondi)');
title('Confronto Prestazioni Sorts');
legend('BubbleSort', 'SelectionSort', 'InsertionSort', 'std::sort', 'Location', 'northwest');