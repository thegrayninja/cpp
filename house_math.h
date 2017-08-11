#ifndef HOUSE_MATH_H_INCLUDED
#define HOUSE_MATH_H_INCLUDED

float smallest_vector(vector<float>vect)
{
    vector<float>smallest_value;
    for (float i : vect)
    {
        if (smallest_value.size() < 1)
        {
            //cout << "It's empty!\n";
            smallest_value.push_back(i);
        }
        else if (i < smallest_value[0])
        {
            smallest_value[0] = i;
        }
    }
    cout << "The smallest value is: " << smallest_value[0] << endl;
    //cout << smallest_value.size() << endl;
    return 0;
}


float largest_vector(vector<float>vect)
{
    vector<float>largest_value;
    for (float i : vect)
    {
        if (largest_value.size() < 1)
        {
            //cout << "It's empty!\n";
            largest_value.push_back(i);
        }
        else if (i > largest_value[0])
        {
            largest_value[0] = i;
        }
    }
    cout << "The largest value is: " << largest_value[0] << endl;
    //cout << largest_value.size() << endl;
    return 0;
}

int is_prime(int value)
{
    for (int i = 2; i < value; ++i)
    {
        if (value%i == 0){cout << "Not a prime number. :(\n\n"; return 0;}
    }
    cout << "Yep, " << value << " is a prime number. Woo woo!\n\n";
    return 0;
}

#endif // HOUSE_MATH_H_INCLUDED
