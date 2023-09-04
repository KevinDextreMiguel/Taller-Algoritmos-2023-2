#include"ArrCompra.h"
#include"ArrCliente.h"
#include"ArrProducto.h"
int menu()
{
	int opc;
	do
	{
		cout << "\n1. Registrar producto";
		cout << "\n2. Registrar cliente";
		cout << "\n3. Registrar Compra";
		cout << "\n4. imprimir productos";
		cout << "\n5. imprimir clientes";
		cout << "\n6. imprimir Compras";
		cout << "\nIngrese una opción: ";
		cin >> opc;
	} while (opc < 1 || opc>6);
	return opc;
}

Producto* agregar_producto(Producto* obj)
{
	int CodProducto;
	string Nombre;
	string Tipo;
	string Marca;
	int cantidad;
	double Precio;
	cout << "\nCodProducto: "; cin >> CodProducto;
	cout << "Nombre: "; cin >> Nombre;
	cout << "Tipo: "; cin >> Tipo;
	cout << "Marca: "; cin >> Marca;
	cout << "cantidad: "; cin >> cantidad;
	cout << "Precio unidad: "; cin >> Precio;
	obj = new Producto(CodProducto, Nombre, Tipo, Marca, cantidad, Precio);
	return obj;
}

Cliente* agregar_cliente(Cliente* obj)
{
	string DNI, Nombres;
	cout << "\nDNI: "; cin >> DNI;
	cout << "Nombres: "; cin >> Nombres;
	obj = new Cliente(DNI, Nombres);
	return obj;
}

Compra* agregar_compra(Compra* objCompra, ArrCliente* objArrCliente, ArrProducto* objArrProducto)
{
	int opc, pos;
	int id;
	string fecha;
	Cliente* objCliente;
	Producto* objProducto;
	cout << "\nid: "; cin >> id;
	cout << "fecha: "; cin >> fecha;
	objArrCliente->info_ArrCliente();
	cout << "\n\n1. Ingresar cliente existente";
	cout << "\n2. Ingresar cliente nuevo";
	cout << "\nOpción: "; cin >> opc;
	//seleccionamos un cliente
	switch (opc)
	{
	case 1:
		cout << "\nPosición: "; cin >> pos;
		objCliente = objArrCliente->get_cliente(pos); break;
	case 2:objCliente = agregar_cliente(objCliente);
	}
	objCompra = new Compra(id, fecha, objCliente);
	opc = 1;
	//agregamos los productos que se va ha comprar
	while (opc==1)
	{
		//mostramos todos los productos que se puede comprar
		objArrProducto->info_ArrProducto();
		cout << "\nPosición: "; cin >> pos;
		//obtenemos un producto del array producto
		objProducto = objArrProducto->get_Producto(pos);
		//agregamos un producto al array de productos de compra
		objCompra->agregar_Producto(objProducto);
		//eliminamos el producto que fue comprado
		objArrProducto->eliminar(pos);

		cout << "\n1 para seguir agregando y 2 para salir: "; cin >> opc;
	}
	return objCompra;
}
int main()
{
	//creamos los objetos
	Cliente* objCliente;
	Producto* objProducto;
	Compra* objCompra;
	ArrProducto* objArrProducto = new ArrProducto();
	ArrCliente* objArrCliente=new ArrCliente();
	ArrCompra* objArrCompra=new ArrCompra();
	int opc;
	while (true)
	{
		system("cls");
		opc = menu();
		switch (opc)
		{
		case 1:
			objProducto = agregar_producto(objProducto);
			objArrProducto->agregar(objProducto); break;
		case 2:
			objCliente = agregar_cliente(objCliente);
			objArrCliente->agregar(objCliente); break;
		case 3:
			objCompra = agregar_compra(objCompra, objArrCliente,objArrProducto);
			objArrCompra->agregar(objCompra); break;
		case 4:objArrProducto->info_ArrProducto(); break;
		case 5:objArrCliente->info_ArrCliente(); break;
		case 6:objArrCompra->info_ArrCompra();
		}
		getch();
	}
	delete objCliente;
	delete objProducto;
	delete objCompra;
	delete objArrCliente;
	delete objArrCompra;
	delete objArrProducto;
}

