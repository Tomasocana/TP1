#pragma once

#include <iostream>
#include <vector>

using namespace std;

class EntidadOrganizativa{
    private:
        string nombre;
        vector<EntidadOrganizativa> subentidades;
    public:
        string getNombre();
        void agregarSubentidad(EntidadOrganizativa* entidad);
        int contarSubentidades();
};

class Empresa : public EntidadOrganizativa , public CentralRegional{
    private:
        vector<Departamento> departamentos;
    public:
        string nombre;
        string direccion;
        Departamento getDepByName(string name);
        vector<Departamento> getDepNames();
};

class CentralRegional : EntidadOrganizativa{
    private:
        int cantEmpleados;
        vector<GerenteAlto> gerentesAlto[4];
        vector<GerenteMedio> gerentesMedio[19];
        vector<Empresa> empresas;
    public:
        int getCantEmpleados();
        vector<string> getEmpNames();
        vector<GerenteAlto> getGerentesAlto();
        vector<GerenteMedio> getGerentesMedio();
};

class Departamento : public Empresa{
    private:
        vector<Empleado> empleados;
    public:
        string nombre;
        string ubicacion;
        int contarEmpleados();
        vector<Empleado> getEmployees();
        bool contratarEmpleado(Empleado empleado);
        bool despedirEmpleado(Empleado empleado);
};

class Empleado : public Departamento{
    private:
        int antiguedad;
        float salario;
        float getSalario();
    public:
        string nombre;
        string puesto;
        int getAntiguedad();
        bool updateSalario(float salario);
};

class Manager : Empleado{
    private:
        float bono;
        string level;
    public:
        bool updateBono(float bono);
        float getBono();
        bool setLevel(string level);
};

class GerenteMedio : public Manager, public CentralRegional{

};

class GerenteAlto : public Manager, public CentralRegional{

};

class GerenteBajo : public Manager{

};

class LiderEquipo : public Manager{

};