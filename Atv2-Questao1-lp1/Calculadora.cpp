#include <iostream>
#include <cmath>
double pi = 3.14;

using namespace std;

// Classe base solidos geometricos
class SolidosGeometricos {
public:
    virtual double calc_area(){
       cout << "Calculo da area de um Solido geometrico da sua escolha!" << endl;
       return 0;
    }
    virtual double calc_vol(){
       cout << "Calculo do volume de um Solido geometrico da sua escolha!" << endl;
       return 0;
    }
};

// Forma de calcular piramides dando comportamento dinamico aos métodos de solidos geometrico (Será assim para todas as outras formas de SolidosGeometricos)
class CalcPiramide : public SolidosGeometricos {
private:
    double base_piramide, altura_piramide;
public:

    virtual double calc_area() override{
        double base_apotema =  ((base_piramide/2)*(base_piramide/2));
        double altura_apotema = ((altura_piramide/2)*(altura_piramide/2));
        double quadrados = base_apotema + altura_apotema;
        double apotema = sqrt(quadrados);
        double area_face = (apotema*base_piramide)/2;
        double area_lateral = area_face*4;

        double area_base = base_piramide*base_piramide;

        double area_piramide = area_base + area_lateral;

        return area_piramide;
    }
    virtual double calc_vol() override{
        double area_base = base_piramide*base_piramide;
        double volume = (area_base*altura_piramide)/3;

        return volume;
    }
    CalcPiramide(double base_input, double altura_input):
        base_piramide(base_input), altura_piramide(altura_input){};
    ~CalcPiramide(){};
};

// Forma de calcular area/volume de cubos
class CalcCubo : public SolidosGeometricos {
private:
    double aresta_base;
public:
    virtual double calc_area() override{
        double area_cubo = 6*(pow(aresta_base,2));
        return area_cubo;
    }
    virtual double calc_vol() override{
        double volume_cubo = pow(aresta_base,3);
        return volume_cubo;
    }
    CalcCubo(double aresta):
        aresta_base(aresta){};
    ~CalcCubo(){};
};

// Forma de calcular area/volume de paralelepipedos
class CalcParalelepipedo : public SolidosGeometricos{
private:
    double aresta1,aresta2,aresta3;
public:
    virtual double calc_area() override{
        double area_aresta_1_2 = 2*(aresta1*aresta2);
        double area_aresta_1_3 = 2*(aresta1*aresta3);
        double area_aresta_2_3 = 2*(aresta2*aresta3);
        double area_paralelepipedo = area_aresta_1_2 + area_aresta_1_3 + area_aresta_2_3;
        
        return area_paralelepipedo;
    }
    virtual double calc_vol() override{
        double volume_paralelepipedo = aresta1*aresta2*aresta3;

        return volume_paralelepipedo;
    }
    CalcParalelepipedo(double aresta_1,double aresta_2, double aresta_3):
        aresta1(aresta_1), aresta2(aresta_2), aresta3(aresta_3){};
    ~CalcParalelepipedo(){};
};

// Forma de calcular area/volume de esferas
class CalcEsfera : public SolidosGeometricos {
private:
    double diametro;
public:
    virtual double calc_area() override{
        double raio = diametro/2;
        double area_esfera = 4*(pi*(pow(raio,2)));
        
        return area_esfera;
    };
    virtual double calc_vol() override{
        double raio = diametro/2;
        double volume_esfera = 4*(pi*(pow(raio,4)))/3;

        return volume_esfera;
    }
    CalcEsfera(double diametro_input):
        diametro(diametro_input){};
    ~CalcEsfera(){};
};

// Chama os metodos calc_area/calc_vol baseado no tipo real do objeto
double calcular_area(SolidosGeometricos* solidosGeometricos){
    return solidosGeometricos->calc_area();
}

double calcular_volume(SolidosGeometricos* solidosGeometricos){
    return solidosGeometricos->calc_vol();
}
