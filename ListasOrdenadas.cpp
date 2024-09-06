#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

struct Libro
{
    int id;
    string name;
    int stock;
    Libro *next;
};

int _id = 0; // Id libro;

void NewBook(Libro *&head, string name, int stock)
{
    Libro *temp = head;
    Libro *nodo = new Libro();

    _id++;

    nodo->id = _id;
    nodo->name = name;
    nodo->stock = stock;
    nodo->next = nullptr;

    if (head == nullptr)
    {
        head = nodo;
    }
    else
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nodo;
    }
}

void GetProductByLowStock(int n, Libro *head)
{
    Libro *book = head;
    int item = 1;
    if (book == nullptr)
    {
        cout << "No hay libros en la lista." << endl;
        return;
    }

    cout << "[" << endl;
    while (book && item <= n && book->stock <= 10)
    {
        cout
            << "    {" << endl
            << "        Id:" << book->id << "," << endl
            << "        Stock:" << book->stock << "," << endl
            << "        Name:" << "'" << book->name << "'" << "," << endl
            << "        State:" << (book->stock < 10 ? "'Pronto a agotarse'" : "'Disponible'") << "," << endl
            << "    }"
            << (book->next ? "," : "") << endl;

        item++;
        book = book->next;
    }
    cout << "]" << endl;
}

void ShowList(Libro *head)
{
    Libro *book = head;
    if (book == nullptr)
    {
        cout << "No hay libros en la lista." << endl;
        return;
    }
    cout << "[" << endl;
    while (book)
    {
        cout
            << "    {" << endl
            << "        Id:" << book->id << "," << endl
            << "        Stock:" << book->stock << "," << endl
            << "        Name:" << "'" << book->name << "'" << "," << endl
            << "        State:" << (book->stock < 10 ? "'Pronto a agotarse'" : "'Disponible'") << "," << endl
            << "    }"
            << (book->next ? "," : "") << endl;

        book = book->next;
    }
    cout << "]" << endl;
}

void DeleteById(Libro *&head, int id)
{
    Libro *temp = head;
    Libro *prev = nullptr;

    while (temp != nullptr && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Libro no encontrado." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = temp->next;
        cout << "Libro eliminado." << endl;
    }
    else
    {
        prev->next = temp->next;
        cout << "Libro eliminado." << endl;
    }

    delete temp;
}

void EditStock(Libro *&head, int id, int cant)
{
    Libro *temp = head;

    while (temp != nullptr && temp->id != id)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Libro no encontrado." << endl;
    }
    else
    {
        temp->stock += cant;
        cout << "Nuevo stock para el libro '" << temp->name << "' es: " << temp->stock << endl;
    }
}

void FreeList(Libro *head)
{
    Libro *temp;
    while (head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    cout << "Memoria liberada" << endl;
}

// Order list by stock
Libro *MidList(Libro *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Libro *fast = head->next;
    Libro *low = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        low = low->next;
    }

    Libro *mid = low->next;
    low->next = nullptr;
    return mid;
}

Libro *UnitList(Libro *left, Libro *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Libro *result = nullptr;

    if (left->stock <= right->stock)
    {
        result = left;
        result->next = UnitList(left->next, right);
    }
    else
    {
        result = right;
        result->next = UnitList(left, right->next);
    }

    return result;
}

Libro *Merge(Libro *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Libro *mid = MidList(head);

    Libro *left = Merge(head);
    Libro *right = Merge(mid);

    return UnitList(left, right);
}

void Menu()
{
    cout << "\nMenu de opciones:" << endl
         << "1. Mostrar libros" << endl
         << "2. Mostrar libros con stock menor a 10" << endl
         << "3. Agregar libro" << endl
         << "4. Eliminar libro por ID" << endl
         << "5. Sumar stock de un libro" << endl // Nueva opción
         << "6. Salir" << endl
         << "Selecciona una opcion: ";
}

int main()
{

    cout << "Iniciando aplicacion...." << endl;
    sleep(3);
    system("clear");

    Libro *head = nullptr;

    // Inicializar libros predefinidos
    NewBook(head, "Cien años de soledad", 50);
    NewBook(head, "El amor en los tiempos del cólera", 30);
    NewBook(head, "La sombra del viento", 26);
    NewBook(head, "1984", 46);
    NewBook(head, "Orgullo y prejuicio", 86);
    NewBook(head, "El gran Gatsby", 6);
    NewBook(head, "Crónica de una muerte anunciada", 8);
    NewBook(head, "El túnel", 7);
    NewBook(head, "Rayuela", 9);
    NewBook(head, "Los miserables", 10);

    head = Merge(head);

    int opcion, n;

    do
    {
        Menu();
        cin >> opcion;
        system("clear");

        switch (opcion)
        {
        case 1:
            ShowList(head);
            break;

        case 2:
            cout << "Ingresa la cantidad de libros que deseas ver: ";
            cin >> n;
            GetProductByLowStock(n, head);
            break;
        case 3:
        {
            int stock;
            string name;

            cout << "Introduce el stock del libro: ";
            cin >> stock; // Lee el valor del stock

            cout << "Introduce el nombre del libro: ";
            cin.ignore();
            getline(cin, name);

            NewBook(head, name, stock);
            cout << "Libro agregado exitosamente." << endl;
            sleep(2);
            system("clear");
            break;
        }

        case 4:
        {
            int id;
            cout << "Introduce el ID del libro que deseas eliminar: ";
            cin >> id;
            DeleteById(head, id);
            sleep(2);
            system("clear");
            break;
        }

        case 5:
        {
            ShowList(head);
            cout << "------------------------------------------------" << endl;

            int id, cant;
            cout << "Introduce el ID del libro cuyo stock deseas editar: ";
            cin >> id;
            cout << "Introduce la cant que deseas sumar al stock del producto (usa valores negativos para restar): ";
            cin >> cant;
            EditStock(head, id, cant);
            sleep(2);
            system("clear");
            break;
        }

        case 6:
            cout << "Saliendo..." << endl;
            sleep(3);
            FreeList(head);
            break;

        default:
            cout << "Opcion no valida. Intenta de nuevo." << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}
