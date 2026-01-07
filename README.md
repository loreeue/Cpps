# Cpps

## 🧱 MÓDULO C++00 – Fundamentos

### ex00: **Megaphone**

Convierte los argumentos de la línea de comandos a mayúsculas. Si no hay entrada, imprime un mensaje por defecto.

### ex01: **My Awesome PhoneBook**

Agenda de contactos que guarda hasta 8. Comandos: `ADD`, `SEARCH`, `EXIT`. Usa clases `PhoneBook` y `Contact`.

---

## 🧠 MÓDULO C++01 – Memoria, referencias y punteros

### ex00: **BraiiiiiiinnnzzzZ**

Clase `Zombie`. Crea zombies en heap o stack. Practica `new`, `delete`, y destructores.

### ex01: **Moar brainz!**

Función `zombieHorde(N, name)` crea N zombies en memoria dinámica. Practica `new[]` y `delete[]`.

### ex02: **HI THIS IS BRAIN**

Muestra direcciones y valores usando una string, un puntero y una referencia. Comparación simple entre ellos.

### ex03: **Unnecessary violence**

Clases `HumanA` (usa referencia) y `HumanB` (usa puntero) con un arma (`Weapon`). Demuestra diferencias entre punteros y referencias.

### ex04: **Sed is for losers**

Reemplaza todas las apariciones de una palabra por otra en un archivo. Sin usar `std::string::replace`.

### ex05: **Harl 2.0**

Clase `Harl` con niveles de log (`debug`, `info`, etc.). Usa punteros a funciones para evitar `if/else`.

### ex06: **Harl filter**

Filtra los mensajes de Harl según el nivel indicado usando `switch`.

---

## 🧮 MÓDULO C++02 – Polimorfismo ad-hoc y sobrecarga de operadores

### ex00: **My First Class in Orthodox Canonical Form**

Implementación de una clase en **forma canónica ortodoxa**, que representa un número de punto fijo con 8 bits fraccionales. Introduce constructor por defecto, de copia, operador de asignación y destructor. Incluye métodos para obtener y establecer el valor bruto (`getRawBits`, `setRawBits`).

### ex01: **Towards a more useful fixed-point number class**

Extensión de la clase anterior para permitir la conversión entre tipos (`int` y `float`). Añade constructores adicionales y funciones como `toInt()` y `toFloat()`. También se sobrecarga el operador `<<` para imprimir fácilmente los valores.

### ex02: **Now we’re talking**

Se implementa la **sobrecarga de operadores** aritméticos (`+`, `-`, `*`, `/`), de comparación (`>`, `<`, `>=`, `<=`, `==`, `!=`) e incrementales (`++`, `--`, en versiones pre y post). Además, se incluyen métodos estáticos `min` y `max` para comparar dos instancias.

### ex03: **BSP (Binary Space Partitioning)**

Implementación de una clase `Point` (también en forma canónica) que usa números de punto fijo para representar coordenadas 2D. Se crea una función `bsp(a, b, c, point)` que determina si un punto está dentro de un triángulo usando barycentric coordinates. Ideal para introducir técnicas geométricas básicas en C++.

---

## 🧬 MÓDULO C++03 – Herencia

### ex00: Aaaaand... OPEN!

Clase ClapTrap con atributos básicos (name, hitPoints = 10, energyPoints = 10, attackDamage = 0). Métodos: attack, takeDamage, beRepaired. Incluye mensajes en constructores, destructores y acciones.

### ex01: Serena, my love!

Clase ScavTrap que hereda de ClapTrap. Inicializa valores distintos (hitPoints = 100, energyPoints = 50, attackDamage = 20). Añade método especial guardGate(). Imprime mensajes personalizados. Demuestra correctamente la cadena de construcción/destrucción.

### ex02: Repetitive work

Clase FragTrap, también derivada de ClapTrap. Inicializa con (hitPoints = 100, energyPoints = 100, attackDamage = 30). Incluye método especial highFivesGuys(). Nuevos mensajes para construcción/destrucción.

### ex03: Now it’s weird!

Clase DiamondTrap, que hereda de FragTrap y ScavTrap (herencia múltiple). Atributos combinados de ambas clases. Añade su propio atributo name y redefine ClapTrap::name como <name>_clap_name. Usa ScavTrap::attack() y añade método whoAmI() que imprime su nombre y el del ClapTrap.

---

## 🧠 MÓDULO C++04 – Polimorfismo, Clases Abstractas e Interfaces

### ex00: Polimorfismo básico

* Se implementan `Animal`, `Dog` y `Cat`, cada uno con su propio `makeSound()`.
* Se muestra el polimorfismo mediante punteros a `Animal*`.
* Se incluye `WrongAnimal` y `WrongCat` para ilustrar el error común de no usar métodos `virtual`.

### ex01: Brainstorming

* Se introduce la clase `Brain` (100 ideas).
* `Dog` y `Cat` contienen un `Brain*` que se instancia con `new`.
* Se gestiona correctamente la memoria en destrucción.
* Se implementa y prueba la **deep copy** en constructor y operador de asignación.

### ex02: Clase abstracta

* Se hace que `Animal` sea una clase abstracta (`makeSound() = 0`).
* Impide que se pueda instanciar directamente.
* Se aplica convención `AAnimal` para mayor claridad.

### ex03: Interfaces y recapitulación

* Se construye un sistema RPG con materias mágicas:

  * `AMateria` es clase base abstracta.
  * `Ice` y `Cure` son clases concretas que implementan `clone()` y `use()`.
* `ICharacter` define la interfaz del personaje; `Character` la implementa con inventario dinámico.
* `IMateriaSource` y `MateriaSource` permiten crear materias a partir de una "plantilla".
* Se requiere **copias profundas**, evitar memory leaks y seguir forma canónica.

---

## 🧾 MÓDULO C++05 – Excepciones, jerarquías y polimorfismo

### ex00: Mommy, when I grow up, I want to be a bureaucrat!

* Se implementa la clase `Bureaucrat`, con un **nombre constante** y un **grado** comprendido entre 1 (máximo rango) y 150 (mínimo).
* Se introducen excepciones personalizadas (`GradeTooHighException`, `GradeTooLowException`) para proteger los invariantes de la clase.
* Se implementan los métodos `gradeUp()` y `gradeDown()`, teniendo en cuenta que **un número menor representa un rango más alto**.
* Se sobrecarga el operador `<<` para mostrar el estado del objeto.
* El ejercicio refuerza el uso de `try/catch` y la validación estricta de estados.

### ex01: Form up, maggots!

* Se introduce la clase `Form`, que interactúa con `Bureaucrat`.
* Un formulario tiene un nombre constante, un estado de firma y grados mínimos para firmar y ejecutar.
* Se implementa el método `beSigned()` que puede lanzar excepciones si el `Bureaucrat` no tiene suficiente rango.
* Se añade `Bureaucrat::signForm()` para encapsular la lógica de firma y el manejo de errores.
* Este ejercicio trabaja la **colaboración entre clases** y la propagación de excepciones.

### ex02: No, you need form 28B, not 28C...

* `Form` se convierte en una **clase abstracta (`AForm`)**, con métodos virtuales.
* Se implementan tres formularios concretos:

  * `ShrubberyCreationForm`: crea un archivo con árboles ASCII.
  * `RobotomyRequestForm`: simula una robotomización con un 50% de éxito.
  * `PresidentialPardonForm`: concede un indulto presidencial.
* Cada formulario sobrescribe el método `execute()`, demostrando **polimorfismo dinámico**.
* Se introduce `Bureaucrat::executeForm()`, que trabaja con referencias a `AForm`.
* Se enfatiza el uso de **destructores virtuales** para evitar undefined behavior al borrar objetos derivados mediante punteros base.

### ex03: At least this beats coffee-making

* Se implementa la clase `Intern`, responsable de crear formularios a partir de un nombre y un target.
* `Intern::makeForm()` devuelve un puntero a `AForm`, sin exponer las clases concretas al código cliente.
* Se aplica un **patrón Factory simplificado**, evitando estructuras largas de `if/else`.
* Este ejercicio refuerza el **desacoplamiento**, el uso de abstracciones y el diseño orientado a responsabilidades.

---

## 🔄 MÓDULO C++06 – Casts y conversión de tipos

### ex00: **Conversion of scalar types**

* Clase `ScalarConverter` no instanciable con método estático `convert`.
* Detecta el tipo real de un literal (`char`, `int`, `float`, `double`).
* Convierte explícitamente a los otros tipos usando **casts de C++**.
* Maneja pseudo-literales (`nan`, `inf`, `-inff`) y errores de conversión.

### ex01: **Serialization**

* Clase `Serializer` no instanciable.
* Convierte un puntero a `uintptr_t` y viceversa.
* Uso controlado de `reinterpret_cast`.
* Verifica que el puntero serializado y deserializado coinciden.

### ex02: **Identify real type**

* Jerarquía simple: `Base` → `A`, `B`, `C`.
* Creación aleatoria de objetos derivados.
* Identificación del tipo real usando `dynamic_cast`.
* Diferencia entre cast con punteros y referencias.

---

## 🧩 MÓDULO C++07 – Templates

Este módulo introduce el uso de **templates en C++98**, permitiendo escribir código **genérico, reutilizable y seguro en tiempo de compilación**. Se trabajan tanto **funciones template** como **templates de clases**, sin usar STL y respetando la forma canónica ortodoxa cuando aplica.

### ex00: **Start with a few functions**

* Implementación de funciones template `swap`, `min` y `max`.
* Funcionan con cualquier tipo que soporte operadores de comparación.
* Si los valores son iguales, `min` y `max` devuelven el segundo parámetro.
* Los templates se definen **obligatoriamente en el header**.
* Introduce resolución de templates en **tiempo de compilación**.

### ex01: **Iter**

* Implementación de la función template `iter`.
* Aplica una función a cada elemento de un array.
* Soporta arrays **const y no const**.
* La función pasada como parámetro puede recibir referencias const o no const.
* Refuerza el paso de funciones genéricas como argumentos.

### ex02: **Array**

* Implementación de una **clase template `Array<T>`**.
* Gestión dinámica de memoria usando `new[]` (sin STL).
* Constructor por defecto, constructor con tamaño, copia profunda y operador de asignación.
* Sobrecarga del operador `[]` con **control de límites** (lanza `std::exception`).
* Método `size()` constante que devuelve el número de elementos.
* Refuerza diseño seguro de contenedores genéricos y manejo correcto de memoria.
