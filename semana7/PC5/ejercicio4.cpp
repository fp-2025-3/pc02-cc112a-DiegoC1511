#include <iostream>
#include <fstream>


using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main() {
    ifstream archivo("ventas.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir ventas.dat" << endl;
        return 1;
    }

    ofstream reporte("reporte.txt");

    Venta v;
    int totalRegistros = 0;
    double monto = 0;

    
    int idVendedorMayor = -1;
    double maxRecaudacionVendedor = -1;

    int idProductoMasVendido = -1;
    int maxUnidadesProducto = -1;


    double recaudacionVendedores[1000] = {0};
    int unidadesProductos[1000] = {0};


    while (archivo.read((char*)&v, sizeof(Venta))) {
        totalRegistros++;
        double montoVenta = v.cantidad * v.precioUnitario;
        monto += montoVenta;

       
        if (v.idVendedor < 1000){
            recaudacionVendedores[v.idVendedor] += montoVenta;
        }

        if (v.idProducto < 1000){
            unidadesProductos[v.idProducto] += v.cantidad;
        }
    }

    
    for (int i = 0; i < 1000; i++) {
        if (recaudacionVendedores[i] > maxRecaudacionVendedor) {
            maxRecaudacionVendedor = recaudacionVendedores[i];
            idVendedorMayor = i;
        }
        if (unidadesProductos[i] > maxUnidadesProducto) {
            maxUnidadesProducto = unidadesProductos[i];
            idProductoMasVendido = i;
        }
    }

    reporte << "--- REPORTE GENERAL DE VENTAS ---" << endl << endl;
    reporte << "Total de registros: " << totalRegistros << endl << endl;
    reporte << "MONTO TOTAL VENDIDO:" << endl;
    reporte << "S/. "<< monto << endl;
    reporte << "---------------------------------" << endl;
    
    reporte << "VENDEDOR CON MAYOR RECAUDACION:" << endl;
    reporte << "ID Vendedor: " << idVendedorMayor << endl;
    reporte << "Total vendido: S/. " << maxRecaudacionVendedor << endl;
    reporte << "---------------------------------" << endl;

    reporte << "PRODUCTO MAS VENDIDO:" << endl;
    reporte << "ID Producto: " << idProductoMasVendido << endl;
    reporte << "Total unidades: " << maxUnidadesProducto << endl;
    reporte << "---------------------------------" << endl;

    reporte << "VENTAS SOSPECHOSAS (cantidad > 100):" << endl << endl;

    
    archivo.clear();
    archivo.seekg(0, ios::beg);

    while (archivo.read((char*)&v, sizeof(Venta))) {
        if (v.cantidad > 100) {
            reporte << "ID Venta: " << v.idVenta << " | Vendedor: " << v.idVendedor 
                    << " | Producto: " << v.idProducto << " | Cantidad: " << v.cantidad << endl;
        }
    }

    archivo.close();
    reporte.close();

    cout << "Reporte generado con exito en reporte.txt" << endl;

    return 0;
}