/*

activo: Deben ordenarse ascendentemente en los nodos del AVL
 ID, generado aleatoriamente
 Nombre
 descripcion
 dias para rentar
 disponible(T,F)




--> Convertir Departamento y Empresa a minusculas, para evitar confuciones por CaseSensitive
--> Posible nombre de empresas con espacio en blanco
---------------------------
!! Preguntar AUX:
--> Si el primer usuario guardado por (DEPARTAMENTO, EMPRESA) queda fijo al momento de agregar mas a la misma posicion 'dado que posee punteros: -delante- y -atras-'
SE DEBE ACTUALIZAR, POR LO QUE EL NUEVO QUE ESTE ADELANTE, PASA A SER EL NUEVO NODO "cabecera" de su "lista"

-->RENTA DE ACTIVOS<--

seccion: Catalogo de activos, muestra todos los que existen en la Matriz o muestra unicamente todos los que coincidan con el mismo (DEPARTAMENTO, EMPRESA) del usuario que realiza el proceso, o unicamente son los -activos- del Usuario que realiza transaccion (Logged).
DEBE MOSTRAR TODOS LOS ACTIVOS, A EXCEPCION DE LA PERSONA QUE SE LOGGEO.

(en catalogo) aparece->
Tiempo de Renta: se asigna en AGREGAR activo(cuando se crea) o unicamente cuando se RENTA
CUANDO SE CRA UN ACTIVO, DEBE IR TAMBIEN EL CAMPO DE: Dias disponibles para rentar.

*(Flujo de aplicacion) dado que indica que Otros usuarios podran rentar esos activos, usuarios de mismo (DEPARTAMENTO, EMPRESA) o todos los que existen en matriz
TODOS


DESPUES: Reportes:
todos los activos pertenecientes a una EMPRESA, disponibles para rentarse (pertenecientes a todos los usuarios que existan o solo de los usuarios que esten al frente)
todos los activos pertenecientes a un DEPARTAMENTO, disponibles para rentarse


============
"en el manual tecnico"
se debe explicar el funcionamiento de los TDA (como funciona cada metodo, proposito; similar como una pequena descripcion)


*******************************
RAIZ        Guate  Izabal
Wallmart    ale01   
Max                 sam123
*******************************
(3)        (2)        (1)
ale01 -> samuel2 -> pajoc33

(3)        (1)         (2)
sam123 -> linduqui -> netoo

*/