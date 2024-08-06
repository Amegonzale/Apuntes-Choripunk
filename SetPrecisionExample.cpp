// Initializing the decimal
double num = 3.142857142857;

cout << "Before setting the precision: \n"
     << num << endl;

// Using setprecision()
cout << "Setting the precision using"
     << " setprecision to 5: \n"
     << setprecision(5);

cout << num << endl;

// Using setprecision()
cout << "Setting the precision using"
       << " setprecision to 9 : \n "
     << setprecision(9);

cout << num << endl;
