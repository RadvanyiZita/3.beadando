#include <iostream>
#include "szamlalo.hpp"
#include "kivalaszto.hpp"
#include "amoba.hpp"
#include <ctime>
#include <vector>
#include<string>
#include <fstream>
using namespace genv;
using namespace std;

int main()
{
    Jatekmester jm(800,600,100);
    jm.run();
    return 0;
}
