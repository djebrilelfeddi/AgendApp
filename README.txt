cmake . -G "MinGW Makefiles" -B build -S . -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -D CMAKE_BUILD_TYPE=Release
cmake --build build

cmake . -G "MinGW Makefiles" -B build -S . -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release
cmake --build build

J'ai fais une liste de ce que je n'aime pas dans mon projet, et pour lesquels j'ai eu la réflexion "de toute façon on m'a pas demandé une fusée":

- Le nom des fichiers similaires qui pourrait porter a confusion:
    > "./include/Agenda/Controller.hpp"
    > "./include/Menu/Controller.hpp"
- Utilisation de RETURNSTATUS (Je trouve ça pas beau et il doit y avoir une meilleure solution)
- Declaration de la template getInput dans ./include/Utils.hpp
- Trop de getters/setters dans ResourceManager (mauvaise structure de données ?)
- Définition des attributs day, month, year dans "./include/Timestamp/Date.hpp" (sinon warning, mais il doit y avoir une autre solution)
- Utilité et syntaxe du destructeur de "./include/Agenda/Controller.hpp"
- Utilité des interfaces pour cette taille de projet, si ce n'est expliciter le comportement des classes qui les utilisent, mais bon je laisse quand meme
- Pas super fan de handleReturnStatus, initializeCommands et initializeActions dans "./include/Menu/Controller.hpp" (Peut etre créer une classe qui s'occupe de ça)
- Le fait que les fonctions du menu soient dans "./include/Menu/Controller.hpp" (addEvent, removeEvent, ...)