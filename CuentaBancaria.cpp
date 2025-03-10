#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
using namespace std;

class CuentaBancaria {
private:
    double saldo;
    bool activa;
    bool bloqueada;
    int intentosFallidos;
    const double LIMITE_SALDO_BAJO = 500.0;

public:
    CuentaBancaria(double _saldo) : saldo(_saldo), activa(true), bloqueada(false), intentosFallidos(0) {}

    void depositar(double monto) {
        if (bloqueada) {
            cout << "Cuenta bloqueada. No se pueden realizar operaciones." << endl;
            return;
        }
        if (!activa) {
            cout << "Cuenta inactiva. No se pueden realizar depósitos." << endl;
            return;
        }
        saldo += monto;
        cout << "Depósito exitoso. Saldo actual: " << saldo << endl;
    }

    void retirar(double monto) {
        if (bloqueada) {
            cout << "Cuenta bloqueada. No se pueden realizar operaciones." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes." << endl;
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                bloqueada = true;
                cout << "Cuenta bloqueada por múltiples intentos fallidos." << endl;
            }
            return;
        }
        saldo -= monto;
        intentosFallidos = 0;
        cout << "Retiro exitoso. Saldo actual: " << saldo << endl;
        if (saldo < LIMITE_SALDO_BAJO) {
            cout << "Advertencia: Saldo bajo." << endl;
        }
    }

    void mostrarSaldo() {
        cout << "Su saldo es: " << saldo << endl;
    }
};

int main() {
    int opcion, cuentaSeleccionada;
    double monto;

    CuentaBancaria cuenta1(1000), cuenta2(1500), cuenta3(2000), cuenta4(2500), cuenta5(3000);
    CuentaBancaria cuenta6(1200), cuenta7(1700), cuenta8(2200), cuenta9(2700), cuenta10(3200);
    CuentaBancaria cuenta11(1300), cuenta12(1800), cuenta13(2300), cuenta14(2800), cuenta15(3300);
    CuentaBancaria cuenta16(1400), cuenta17(1900), cuenta18(2400), cuenta19(2900), cuenta20(3400);
    CuentaBancaria cuenta21(1100), cuenta22(1600), cuenta23(2100), cuenta24(2600), cuenta25(3100);
    CuentaBancaria cuenta26(900), cuenta27(1400), cuenta28(1900), cuenta29(2400), cuenta30(2900);

    do {
        cout << "\nSeleccione una cuenta bancaria (1-30): ";
        cin >> cuentaSeleccionada;

        if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
            cout << "Cuenta no válida. Intente de nuevo." << endl;
            continue;
        }

        CuentaBancaria* cuenta;

        if (cuentaSeleccionada == 1) cuenta = &cuenta1;
        else if (cuentaSeleccionada == 2) cuenta = &cuenta2;
        else if (cuentaSeleccionada == 3) cuenta = &cuenta3;
        else if (cuentaSeleccionada == 4) cuenta = &cuenta4;
        else if (cuentaSeleccionada == 5) cuenta = &cuenta5;
        else if (cuentaSeleccionada == 6) cuenta = &cuenta6;
        else if (cuentaSeleccionada == 7) cuenta = &cuenta7;
        else if (cuentaSeleccionada == 8) cuenta = &cuenta8;
        else if (cuentaSeleccionada == 9) cuenta = &cuenta9;
        else if (cuentaSeleccionada == 10) cuenta = &cuenta10;
        else if (cuentaSeleccionada == 11) cuenta = &cuenta11;
        else if (cuentaSeleccionada == 12) cuenta = &cuenta12;
        else if (cuentaSeleccionada == 13) cuenta = &cuenta13;
        else if (cuentaSeleccionada == 14) cuenta = &cuenta14;
        else if (cuentaSeleccionada == 15) cuenta = &cuenta15;
        else if (cuentaSeleccionada == 16) cuenta = &cuenta16;
        else if (cuentaSeleccionada == 17) cuenta = &cuenta17;
        else if (cuentaSeleccionada == 18) cuenta = &cuenta18;
        else if (cuentaSeleccionada == 19) cuenta = &cuenta19;
        else if (cuentaSeleccionada == 20) cuenta = &cuenta20;
        else if (cuentaSeleccionada == 21) cuenta = &cuenta21;
        else if (cuentaSeleccionada == 22) cuenta = &cuenta22;
        else if (cuentaSeleccionada == 23) cuenta = &cuenta23;
        else if (cuentaSeleccionada == 24) cuenta = &cuenta24;
        else if (cuentaSeleccionada == 25) cuenta = &cuenta25;
        else if (cuentaSeleccionada == 26) cuenta = &cuenta26;
        else if (cuentaSeleccionada == 27) cuenta = &cuenta27;
        else if (cuentaSeleccionada == 28) cuenta = &cuenta28;
        else if (cuentaSeleccionada == 29) cuenta = &cuenta29;
        else cuenta = &cuenta30;

        cout << CYAN << "\n===== MENU DE CUENTA BANCARIA =====" << RESET << endl;
        cout << GREEN << "1. Depositar" << RESET << endl;
        cout << RED << "2. Retirar" << RESET << endl;
        cout << YELLOW << "3. Consultar saldo" << RESET << endl;
        cout << BLUE << "4. Salir" << RESET << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << GREEN << "Ingrese monto a depositar: "<< RESET <<endl;
            cin >> monto;
            cuenta->depositar(monto);
            break;
        case 2:
            cout << RED << "Ingrese el monto a retirar: "<< RESET <<endl;
            cin >> monto;
            cuenta->retirar(monto);
            break;
        case 3:
            cout << YELLOW << "Opción de consulta de saldo seleccionada." << RESET << endl;
            cin >> monto;
            cuenta->mostrarSaldo();
            break;
        case 4:
            cout << BLUE << "Saliendo del sistema..." << RESET << endl;
            break;
        default:
            cout << RED << "Opcion no valida. Intente de nuevo." << RESET << endl;
        }

    } while (opcion != 4);

    return 0;
}
