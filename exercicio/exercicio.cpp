#include <iostream>
#include <memory>

using namespace std;

class Coord
{
    private:
        // Coordenadas (dado um upgrade de int para float também :P)
        float x, y;
    public:
        void InitCoord(float new_x, float new_y);
};

class Cube
{
    private:
        // Coordenadas do cubo
        float x, y, z;
    public:
        void InitCube(float new_x, float new_y, float new_z);
        void CubePrintVolume(Cube c);        
        //~Cube();
};
// Inicializa Coordenadas
void Coord::InitCoord (float new_x, float new_y)
{
    x = new_x;
    y = new_y;
}
// Inicializa Coordenadas do Cubo
void Cube::InitCube (float new_x, float new_y, float new_z)
{
    x = new_x;
    y = new_y;
    z = new_z;
}
// Calcula volume do Cubo e imprime 
void Cube::CubePrintVolume(Cube c)
{
    float volume = (c.x) * (c.y) * (c.z);
    cout << volume << endl;
}
/*
Cube::~Cube()
{
    cout<<"Goodbye EasterEgg"<<endl;
}
*/
int main()
{
    unique_ptr <Coord> c1 (new Coord);
    unique_ptr <Cube> c2 (new Cube);

    (*c1).InitCoord(50, 10);
    (*c2).InitCube(10, 20, 30);
    (*c2).CubePrintVolume(*c2);

    return 0;
}