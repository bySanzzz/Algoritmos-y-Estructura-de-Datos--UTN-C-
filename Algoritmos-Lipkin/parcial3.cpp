#include <iostream>
using namespace std;
#define MAX_ELEMENTOS_PRODUCTOS 1000;
#define MAX_ELEMENTOS_VENTAS 5000;

struct CatalogoProductos
{
    int CodigoProducto;
    string Descripcion;
    float Precio;
    int Stock;
    int UnidadesVendidas;

};

struct RegistrosDeVentas
{
    int CodigoProductoVentas;
    int CantidadVendida;
    int NumerodeFactura;
};

int calcularPrecioHotWeek(CatalogoProductos vecCatalogo[], int tamVecCatalogo, int productoId){
    int descuento, precioDescuento;
    for (int j = 0; j < tamVecCatalogo; j++){
        if (vecCatalogo[j].CodigoProducto == productoId){
        descuento=(vecCatalogo[j].Precio * 15) /100 ;
        precioDescuento = vecCatalogo[j].Precio - descuento;
        break;
        }
    }
    return precioDescuento;
}
void procesadorDeVentas(CatalogoProductos vecCatalogo[], int tamVecCatalogo, 
RegistrosDeVentas vecRegistros[], int tamVecRegistros){
    for (int j = 0; j < tamVecCatalogo; j++){
        int TotalVendidas = 0;
        for(int i = 0; i < tamVecRegistros; i++){
            if (vecCatalogo[j].CodigoProducto == vecRegistros[i].CodigoProductoVentas){
                TotalVendidas = vecRegistros[i].CantidadVendida + TotalVendidas;
            }
        } 
    int descuentoRecaudacion = calcularPrecioHotWeek(vecCatalogo,tamVecCatalogo,vecCatalogo[j].CodigoProducto);
        
    } 
}
