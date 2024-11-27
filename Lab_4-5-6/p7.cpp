#include <iostream>
using namespace std;

class CubeMaker;

class Cuboid{
private:
    float length;
    float width;
    float height;

public:
    Cuboid(float l, float w, float h):length(l), width(w), height(h){}
    float area(){
        return 2*(length*width+width*height+height*length);
    }

    friend class CubeMaker;

    void display(){
        cout<<"Dimensions of Cuboid (L x W x H): "<<length<<" x "<<width<<" x "<<height<<endl;
    }
};

class CubeMaker{
public:
    void convertToCube(Cuboid &c){
        float minDim = min(c.length, min(c.width, c.height));
        c.length = c.width = c.height = minDim;
    }
};

int main(){
    Cuboid cuboid(4.0, 5.0, 6.0);

    cout << "Original ";
    cuboid.display();
    cout << "Surface area of the cuboid: " << cuboid.area() << endl;

    CubeMaker maker;
    maker.convertToCube(cuboid);

    cout << "\nAfter converting to a cube:" << endl;
    cuboid.display();
    cout << "Surface area of the cube: " << cuboid.area() << endl;

    return 0;
}