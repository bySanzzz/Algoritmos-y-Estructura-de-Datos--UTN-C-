#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    return 0;
}

struct Empleado{
    int legajo;
    float sueldo;
};

/*
binarios -> pueden usar estructuras -> 2 tipos (.bin y .dat)

"empleados.bin"
*/

void formaUno(char rutaArchEmpleados[]){
    //como abro un archivo
    /*
    FILE *archNombre = fopen(rutaArch,"modoApertura");

    rb: solo lectura, el archivo debe existir previamente
    wb: solo escritura, el archivo debe existir previamente 
    ab: lectura y escritura, si el archivo no existe, lo crea. Si existe, permite la escritura en la posición libre
    rb+: lectura y escritura, sobreescritura -> el archivo debe existir previamente.
    wb+: lectura y escritura, sobreescritura -> si el archivo no existe, lo crea. Si existe, pisa el archivo anterior.
    */
    FILE *archEmpleado = fopen(rutaArchEmpleados,"rb+");

    //verificar que ese archivo se haya podido abrir
    if(archEmpleado == NULL){
        //el archivo no se pudo abrir
        cout << "no se pudo abrir el archivo" << endl;
        return;
    }

    //como leo un archivo
    //Necesito una variable para guardar los datos que voy leyendo, la misma tiene el mismo td del archivo
    Empleado rEmp;
    //fread(&varible,cuantoMide[sizeof(Estructura)],cuantosRegLeo,archNombre); -> 1 si pudo leer algo, 0 si no.
    fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    cout << rEmp.legajo << rEmp.sueldo << endl;
    
    //leer secuencialmente un archivo
    
    while(fread(&rEmp, sizeof(Empleado),1,archEmpleado)){
        cout << rEmp.legajo << rEmp.sueldo << endl;
    }
    
    //formaDos de leer
    fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    while(!feof(archEmpleado)){
        cout << rEmp.legajo << rEmp.sueldo << endl;
        fread(&rEmp, sizeof(Empleado),1,archEmpleado);
    }
    
    //escribir en un archivo
    
    Empleado buffer;
    buffer.legajo = 83948;
    buffer.sueldo = 200000;
    //fwrite(&varible,cuantoMide[sizeof(Estructura)],cuantosRegEscribo,archNombre);
    fwrite(&buffer, sizeof(Empleado),1,archEmpleado);
    
    Empleado vecEmpleado[50000];
    int tamVecEmpleado = 50000;
    fwrite(vecEmpleado, sizeof(Empleado),tamVecEmpleado,archEmpleado);


    //fseek(archNombre,cuantoMeMuevo[n * sizeof(Estructura)],desdeDonde)
    /*
    SEEK_SET: desde el inicio del archivo
    SEEK_END: desde el final del archivo
    SEEK_CUR: desde la posición actual del archivo
    */

    //modifcar el sueldo del empleado con legajo 5000, sumarle 100000 al sueldo

    Empleado regEmpleado;
    while(fread(&regEmpleado,sizeof(Empleado),1,archEmpleado)){
        if(regEmpleado.legajo == 5000){
            fseek(archEmpleado,-1 * sizeof(Empleado),SEEK_CUR);
            regEmpleado.sueldo + 100000;
            fwrite(&regEmpleado,sizeof(Empleado),1,archEmpleado);
        }
    }

    fclose(archEmpleado);
}

typedef char str50[51];

struct Alumno{
    int legajo;
    str50 nombre;
    float promedio;
    bool activo;
};


void funcion(){
    Alumno data;
    //strcpy(vecDestino,cadOrigen);
    strcpy(data.nombre,"Santiago");
    
    //strcmp(cadUno,cadDos); -> [izq: -1, centro: 0, der: 1];
    //strcmp(Santiago,Santiago); -> 0 
}
/*Alta de Registros: Crear una función agregarAlumno que permita ingresar los datos de un alumno y lo guarde en el archivo alumnos.dat. */

void agregarAlumnos(char rutaArchAlumnos[]){
    FILE *archAlumnos = fopen(rutaArchAlumnos,"ab");
    if(archAlumnos == NULL){
        return;
    }

    Alumno data;
    cout << "Ingrese nombre: "; cin > data.nombre;
    cout << "Ingrese legajo: "; cin > datos.legajo;
    cout << "Ingrese promedio: "; cin > datos.promedio;

    fwrite(&datos,sizeof(Alumno),1,archAlumnos);

    fclose(archAlumnos);
}

/*Realizar una función listarAlumnos que lea el archivo alumnos.dat registro por registro y muestre los datos de todos los alumnos. */
void listarALumnos(char rutaArchAlumnos[]){
    FILE *archAlumnos = fopen(rutaArchAlumnos,"rb");
    if(archAlumnos == NULL){
        return;
    }
    Alumno data;
    while(fread(&data,sizeof(Alumno),1,archAlumnos)){
        cout << "Nombre: " << data.nombre;
        cout << "legajo: "<< data.legajo;
        cout << "Promedio: " << data.promedio;
    }
    fclose(archAlumnos);

}
--------------- Segunda Parte -------------------

//6. Búsqueda Secuencial: Diseñar una función que reciba un número de legajo, 
//busque ese alumno en el archivo y, si lo encuentra, muestre su nombre y 
//promedio. Si no existe, informar con un mensaje.// 
void numLegajo(char rutaArch[], int legajoBuscar){
    FILE *archAlumnos= fopen(rutaArch,"rb");
    if (archAlumnos == NULL){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    Alumno data;
    bool encontrado = false;
    while(fread(&data,sizeof(Alumno),1,archAlumnos)){
        if (data.legajo == legajoBuscar){
            cout << " Alumno encontrado "<< endl;
            cout << data.nombre << endl;
            cout << data.promedio << endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false){
        cout << "No se encotro al Alumno buscado" << endl;
    }
    fclose(archAlumnos);
    }

/*
=====================================================
CONSIGNA 7 - Filtro
Crear una función que genere un archivo de texto aprobados.txt
(legible por humanos) que contenga solamente los nombres y
promedios de los alumnos que tengan promedio superior a 6.
=====================================================
*/
void crearArchivo( char rutaArch [], char rutaArchCrear[]){
    FILE *archAlumnos = fopen(rutaArch,"rb");
    FILE *ArchNuevo = fopen(rutaArchCrear,"wb");
    if (archAlumnos == NULL || ArchNuevo == NULL){
        cout << "No se pudo abrir el archivo"<< endl;
        return;
    }
    Alumno auxRead;
    ALumno auxWrite;
    while(fread(&auxRead,sizeof(Alumno),1,archAlumnos)){
        if (auxRead.promedio > 6){
            fwrite(&auxWrite,sizeof(Alumno),1,ArchNuevo)//fprintf veremos
        }
    }
    fclose(archAlumnos);
    fclose(ArchNuevo);
}


/*
=====================================================
CONSIGNA 8 - Modificación de un campo
Realizar una función que pida un legajo al usuario. Si el alumno
existe, debe permitir modificar su promedio.
(Estrategia: buscar el registro, posicionar el puntero del archivo
en la posición correcta usando fseek, y sobrescribir el registro
modificado).
=====================================================
*/
void modPromedio(char rutaArch[], int legajo, int newPromedio){
    FILE * archBaja = fopen(rutaArch,"rb+");
    if (archBaja == NULL){
        cout << "No se abrio el archivo"<< endl;
        return;
    }
    bool encontrado = false;
    Alumno aux;
    
    while (fread(&aux,sizeof(Alumno),1,archBaja)){
        if (aux.legajo == legajo){ 
            fseek(archBaja, -1 * sizeof(Alumno),SEEK_CUR); //me recomienda usar una variable -(long)sizeof(alumno)
            aux.promedio = newPromedio;
            fwrite(&aux, sizeof(Alumno), 1, archBaja);
        encontrado = true;
        break;
        }
    }
    if (encontrado == false){
        cout << "No se encontro el Alumno"<<;
    }

    fclose(archBaja);

}



/*
=====================================================
CONSIGNA 9 - Baja lógica
Diseñar una función que reciba un legajo y realice una "baja lógica".
Esto significa buscar el registro y cambiar el campo activo a false,
sobrescribiendo el registro en el archivo. No se borra físicamente
el dato, solo se marca.
=====================================================
*/
void bajaAlumnos(char rutaArch[], int legajo){
    FILE * archBaja = fopen(rutaArch,"rb+");
    if (archBaja == NULL){
        cout << "No se abrio el archivo"<< endl;
        return;
    }
    bool newEstado = false;// Entiendo que la idea no es cambiar el estado, es solamente ponerlo a false
    bool encontrado = false;
    Alumno aux;
    
    while (fread(&aux,sizeof(Alumno),1,archBaja)){
        if (aux.legajo == legajo){ 
            fseek(archBaja, -1 * sizeof(Alumno),SEEK_CUR); 
            aux.activo = newEstado;
            fwrite(&aux, sizeof(Alumno), 1, archBaja);
        encontrado = true;
        break;
        }
    }
    if (encontrado == false){
        cout << "No se encontro el Alumno"<<;
    }

    fclose(archBaja);

}



/*
=====================================================
CONSIGNA 10 - Listado de activos
Modificar la función del ejercicio 5 para que solo muestre por
pantalla a los alumnos que tengan el campo activo en true.
=====================================================
*/
// Tu resolución acá
void listarALumnos(char rutaArchAlumnos[]){
    FILE *archAlumnos = fopen(rutaArchAlumnos,"rb");
    if(archAlumnos == NULL){
        cout << "no se abrio" << endl;
        return;
    }
    Alumno data;
    while(fread(&data,sizeof(Alumno),1,archAlumnos)){
        if (data.activo == true){
        cout << "Nombre: " << data.nombre << endl;
        cout << "legajo: "<< data.legajo << endl;
        cout << "Promedio: " << data.promedio << endl;
        }
    }
    fclose(archAlumnos);

}


/*
=====================================================
CONSIGNA 11 - De archivo a vector
Dado un archivo alumnos.dat con, a lo sumo, 100 registros, cargar
todos los alumnos activos en un vector en memoria.
(Esto se hace para poder ordenar o trabajar más rápido).
=====================================================
*/
// Tu resolución acá
#define MAX_ELEMENTOS_ALUMNOS 100

void vectorizandoArch(char rutaArch[], Alumno vecAlumno [], int &tamVecAlumno )
    FILE *archAlumnos = fopen(rutaArch, "rb" );
    if (archAlumnos == NULL){
        cout << "No se pudo abrir el archivo"<< endl;
    }
    int tamVecAlumno = 0;
    Alumno aux;
    while(fread(&aux,sizeof(Alumno),1,archAlumnos)){
        if (aux.activo == true){
            vecAlumno[tamVecAlumno] = aux;
            tamVecAlumno ++;
        }
    }
    fclose(archAlumnos);


/*
=====================================================
CONSIGNA 12 - Ordenamiento y back-up
Tomando el vector cargado en el ejercicio anterior, ordenarlo
alfabéticamente por nombre. Luego, guardar este listado ordenado
en un nuevo archivo llamado alumnos_ordenados.dat.
=====================================================
*/
void ordenamiento(Alumno vecAlumno[], int tamVecAlumno){
    Alumno aux;
    for(int i = 0; i < tamVecAlumno - 1; i++){
        for(int j = 0; j < tamVecAlumno - 1 - i; j++){
            if(vecAlumno[j].nombre > vecAlumno[j+1].nombre){ //El enunciado no espera que haya 2 personas con el mismo nombre asi que ignoro la posibilidad
                aux = vecAlumno[j];
                vecAlumno[j] = vecAlumno[j+1];
                vecAlumno[j+1] = aux;
            }
        }
    }
}
void creatNewArch(char rutaArch[],Alumno vecAlumno[], int tamVecAlumno){
    FILE * newArch = fopen(rutaArch, "wb+");
    if (newArch == NULL){
        cout << "No se abrio el archivo"<<endl;
        return;
    }
    Alumno auxCreate;
    for(int i = 0; i < tamVecAlumno; i++){
        auxCreate = vecAlumno[i]; 
        fwrite(&auxCreate,sizeof(Alumno),1,newArch);
    }
    fclose(newArch);
}




/*
=====================================================
CONSIGNA 13 - Baja física (compactación)
Dado el archivo alumnos.dat que contiene registros activos (true)
e inactivos (false), generar un archivo temporal que contenga solo
los activos. Luego, eliminar el archivo original y renombrar el
temporal como alumnos.dat.
=====================================================
*/
void createAndDelete(char rutaArchOriginal [], char rutaArchTemporal []){
    FILE * ArchOriginal = fopen(rutaArchOriginal, "rb");
    FILE * ArchTemporal = fopen(rutaArchTemporal, "wb+");
    if (ArchOriginal == NULL || ArchTemporal == NULL){
        cout << "No se encontro archivo buscado"<<endl;
        return;
    }
    Alumno aux;
    while(fread(&aux,sizeof(Alumno),1,ArchOriginal)){
        if (aux.activo == true){
            fwrite(&aux,sizeof(Alumno),1,ArchTemporal);
        }
    }
    fclose(ArchOriginal);
    fclose(ArchTemporal);
    remove(rutaArchOriginal); // Metodo de eliminar archivo
    rename(rutaArchTemporal, rutaArchOriginal); // Renombrar Archivo
}


/*
=====================================================
CONSIGNA 14 - Corte de control (simulado)
Se tiene un archivo ventas.dat con registros (codigo_producto,
cantidad_vendida). El archivo está ordenado por código de producto.
Se pide leer el archivo y mostrar el total de unidades vendidas por
cada producto.
(Ejemplo: si hay 3 registros del producto 'A' con cantidades 10, 5
y 5, mostrar "Producto A: 20 ventas total").
=====================================================
*/
struct Ventas {
    char  codigo_producto[10];
    int cantidad_vendida;
}
void ventasRegistros(char rutaArchVentas[]){
    FILE * ArchVentas = fopen(rutaArchVentas, "rb");
    if (ArchVentas == NULL){
        cout << "No se pudo abrir el Archivo" << endl;
        return;
    }
    Ventas aux;
    if (fread(&aux, sizeof(Ventas), 1, ArchVentas) == 1){ // Inicializo la variable con el primer codigo moviendo el puntero 1 vez por el primer registro
        char cod_productoActual = aux.codigo_producto;
        int total = aux.cantidad_vendida;

        while (fread(&aux, sizeof(Ventas), 1, ArchVentas)){// Sigo moviendo el archivo al completo para poder todos los registros
            if (aux.codigo_producto == cod_productoActual){
                total += aux.cantidad_vendida;               // contabilizar en caso que sea el mismo producto
            } else {
                cout << "Producto " << cod_productoActual << ": " << total << " ventas total" << endl;
                cod_productoActual = aux.codigo_producto;    // empieza el producto nuevo
                total = aux.cantidad_vendida;                // con la cantidad de este registro
            }
        }
        cout << "Producto " << cod_productoActual << ": " << total << " ventas total" << endl;
        }
    }



/*
=====================================================
CONSIGNA 15 - Apareo de archivos (merge)
Se tienen dos archivos cursoA.dat y cursoB.dat, ambos ordenados por
legajo de menor a mayor. Generar un tercer archivo todos.dat que
contenga a los alumnos de ambos cursos, manteniendo el orden por
legajo.
(Nota: se debe leer de a un registro de cada archivo y comparar
para decidir cuál escribir primero).
=====================================================
*/
void archivoOrdenado(char rutaArchCursoA [],char rutaArchCursoB [],char rutaArchTotal []){
    FILE * ArchCursoA = fopen (rutaArchCursoA,rb);
    FILE * ArchCursoB = fopen (rutaArchCursoB,rb);
    FILE * ArchCursoTotal = fopen (rutaArchTotal,ab);
    if (ArchCursoA == NULL || ArchCursoB == NULL || archAlumnos == NULL){
        cout << "No se pudo abrir el archivo" << endl;
    }
    Alumno aux; 
    while(fread())
}

Alumno a, b;
    bool hayA = fread(&a, sizeof(Alumno), 1, archA) == 1;   // primer registro de A
    bool hayB = fread(&b, sizeof(Alumno), 1, archB) == 1;   // primer registro de B

    while (hayA && hayB){
        if (a.legajo <= b.legajo){
            fwrite(&a, sizeof(Alumno), 1, archTodos);
            hayA = fread(&a, sizeof(Alumno), 1, archA) == 1;
        } else {
            fwrite(&b, sizeof(Alumno), 1, archTodos);
            hayB = fread(&b, sizeof(Alumno), 1, archB) == 1;
        }
    }

    while (hayA){   // sobró algo de A
        fwrite(&a, sizeof(Alumno), 1, archTodos);
        hayA = fread(&a, sizeof(Alumno), 1, archA) == 1;
    }

    while (hayB){   // sobró algo de B
        fwrite(&b, sizeof(Alumno), 1, archTodos);
        hayB = fread(&b, sizeof(Alumno), 1, archB) == 1;
    }

    fclose(archA);
    fclose(archB);
    fclose(archTodos);
}

/*
=====================================================
CONSIGNA 16 - Actualización de stock (maestro-novedades)
- Maestro: productos.dat (id, descripcion, stock_actual).
- Novedades: ventas_del_dia.dat (id, cantidad_vendida).
Recorrer el archivo de ventas y, por cada venta, buscar el producto
correspondiente en el archivo maestro y restar la cantidad vendida
al stock actual. Actualizar el archivo maestro.
=====================================================
*/
// Tu resolución acá

