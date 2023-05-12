#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double radian(double degree)
{
     double pi = 3.14159265359;
     return (degree * (pi / 180));
}
int main()
{    
    srand(time(0));
    int rec = 0, rep=0 , vol=0;
double F, Bc, Aof, Sb, Uw, H, Sp, Swif , Cd, dof, bt, tlbs, tosab, tosat , th ,loh , lot,sv,PA , PP ,FS ,Factor_s ;
    for (rec = 0; rec < 1000000; rec++)
    {
        double mul = 1;
        double height;

        double shear_key;
        double friction;
        friction =(double)(3+(rand() % 6))/10;
       
        double bearing_capacity;
        bearing_capacity = 100 + (rand() % 500);
       
        double angle_of_friction;
        angle_of_friction = 20 + (rand() % 20);
        
        double alpha = 90 - angle_of_friction;
        double slope_backfill;
        slope_backfill = 5+(rand() % 30);
        
        double unit_weight;
        unit_weight = 14 + (rand() % 8);
       
        height = 3 + (rand() % 13);
        
        double surcharge_pressure;
        surcharge_pressure = 1 + (rand() % 99);
        
        double soil_wall_interface_friction;
        soil_wall_interface_friction = 10 + (rand() % 20);
        
        double concrete_density = 23 + (rand() % 2);
      rep=0;  
     step1:
    double ka, kp, pa, pp, sumv, vself, vsoil, vsurcharge, FOS;
     kp = 1 / ka;
     double depth_of_foundation;
     double temp = (bearing_capacity * pow(((1 - sin(radian(angle_of_friction))) / (1 +     sin(radian(angle_of_friction)))), 2) / unit_weight);
   depth_of_foundation=(mul+(double)(3+(rand() % 20))/100)*temp;

     double total_height = depth_of_foundation + height;

     double base_thickness=total_height/15;
     base_thickness=( mul+(double)(3+(rand() % 20))/100)*base_thickness;
     double term = (sin(radian(angle_of_friction + soil_wall_interface_friction)) * sin(radian(angle_of_friction - slope_backfill))) / (sin(radian(alpha - soil_wall_interface_friction)) * sin(radian(alpha + slope_backfill)));
     if (term < 0)
          term = term * (-1);
     ka = (pow(sin(radian(alpha + angle_of_friction)), 2)) / (pow(sin(radian(alpha)), 2) * sin(radian(alpha + soil_wall_interface_friction)) * (pow(1 + pow(term, 0.5), 2)));
     kp = 1 / ka;
     pa = 0.5 * ka * unit_weight * total_height * total_height;
     pp = 0.5 * kp * depth_of_foundation * depth_of_foundation * unit_weight;

          double thickness_of_stem_at_base;
        thickness_of_stem_at_base=base_thickness;
     double thickness_of_stem_at_top;
     thickness_of_stem_at_top=( mul+(double)(3+(rand() % 20))/100)*150;
     thickness_of_stem_at_top = thickness_of_stem_at_top / 100;

     double total_length_base_slab;
      total_length_base_slab=( mul+(double)(3+(rand() % 20))/100)*pow(1.5 * pa / unit_weight, 0.5);

     double length_of_toe;
     length_of_toe = 0.33 * total_length_base_slab;
    double length_of_heel = 0.66 * total_length_base_slab - thickness_of_stem_at_base;
    vself = concrete_density * (base_thickness * total_length_base_slab + 0.5 * (thickness_of_stem_at_base + thickness_of_stem_at_top) * (total_height - base_thickness));
     vsurcharge = (length_of_heel - base_thickness) * surcharge_pressure;
     vsoil = unit_weight * ((length_of_heel - base_thickness) * (total_height - base_thickness) + 0.5 * (length_of_heel - base_thickness) * (length_of_heel - base_thickness) * tan(radian(slope_backfill)));
     sumv = vself + vsoil + vsurcharge;
     pa = (0.5 * ka * unit_weight * (total_height - base_thickness) * (total_height - base_thickness)) + surcharge_pressure * (total_height - base_thickness);


             

        if ((friction * sumv + pp) / pa <= 1.5)
     {
              mul=mul+0.01;
               goto step1;
          }
          else
          {   



            if (rep==0)
{vol= (base_thickness*total_length_base_slab)+(thickness_of_stem_at_base+thickness_of_stem_at_top)*(total_height-base_thickness)/2;
  F=friction;
                Bc=bearing_capacity;
                Aof=angle_of_friction;
                Sb=slope_backfill;
                Uw= unit_weight;
                H= height;
                Sp= surcharge_pressure;
                Swif= soil_wall_interface_friction;
                Cd=concrete_density ;
           
             dof=depth_of_foundation;
             bt=base_thickness;
             tlbs = total_length_base_slab;
             tosab= thickness_of_stem_at_base;
             tosat= thickness_of_stem_at_top;
             th= total_height;
             loh=length_of_heel;
             lot= length_of_toe;
             sv= sumv ;
             PA= pa ;
             PP=  pp ;
             FS= friction * sumv;
             Factor_s=  (friction * sumv + pp) / pa ;
vol=(base_thickness*total_length_base_slab)+(thickness_of_stem_at_base+thickness_of_stem_at_top)*(total_height-base_thickness)/2;}
                if (vol>(base_thickness*total_length_base_slab)+(thickness_of_stem_at_base+thickness_of_stem_at_top)*(total_height-base_thickness)/2)
{              
                F=friction;
                Bc=bearing_capacity;
                Aof=angle_of_friction;
                Sb=slope_backfill;
                Uw= unit_weight;
                H= height;
                Sp= surcharge_pressure;
                Swif= soil_wall_interface_friction;
                Cd=concrete_density ;
            
             dof=depth_of_foundation;
             bt=base_thickness;
             tlbs = total_length_base_slab;
             tosab= thickness_of_stem_at_base;
             tosat= thickness_of_stem_at_top;
             th= total_height;
             loh=length_of_heel;
             lot= length_of_toe;
             sv= sumv ;
             PA= pa ;
             PP=  pp ;
             FS= friction * sumv;
             Factor_s=  (friction * sumv + pp) / pa ;
vol=(base_thickness*total_length_base_slab)+(thickness_of_stem_at_base+thickness_of_stem_at_top)*(total_height-base_thickness)/2;}
            rep=rep+1;
             if (rep<1000)
               { goto step1;
                   mul=1;
               }
    else
{
                cout<<F<<",";
                cout<< Bc<<",";
                cout<<Aof<<",";
                cout<<Sb<<",";
                cout<< Uw <<",";
                cout<< H <<",";
                cout<< Sp <<",";
                cout<< Swif<<",";
                cout<<Cd <<",";
             cout<<dof  <<",";
             cout<< bt<<",";
             cout<< tlbs <<",";
             cout<<tosab <<",";
             cout<<tosat <<",";
             cout<< th <<",";
             cout<< loh <<",";
             cout<< lot <<",";
             cout << sv <<",";
             cout << PA <<",";
             cout <<  PP <<",";
             cout  << FS<<",";
             cout <<  Factor_s<<",";
            cout<<vol<<"\n";   
}


          }
     
    }

     return 0;
}