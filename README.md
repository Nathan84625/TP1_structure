# TP1_structure

## Choix de conception

### 1. Liste chaînée générique avec noeud d'en-tête
Nous utilisons un `template <typename Objet>` pour réutiliser la même classe Liste
pour `Client`, `Commande` et `Biscuit`.

### 2. `ValeurCourante()` retourne une référence
Il y a deux surcharges :

Objet& ValeurCourante();
const Objet& ValeurCourante() const;

Cela permet de modifier un élément directement dans la liste (par exemple
additionner les quantités d'un biscuit) et évite des copies inutiles. La
version `const` garantit la lecture seule sur une liste constante.
Au départ, la fonction retournait une copie, ce qui rendait les
modifications inefficaces et les pointeurs invalides.

## Utilisation de l'ia

#### Nathan
Principalement utilisé pour m'informer et clarifier certain point. L'ia a été utiliser pour déboguer certaine partie de code. Elle été peu utiliser pour générer du code.

#### Traicy
 L’intelligence artificielle a été utilisée comme outil d’aide pour comprendre certaines notions, notamment les listes chaînées et les pointeurs. L’IA a également été utilisée pour corriger et vérifier certaines parties du code. Les solutions proposées ont été relues par l’équipe avant leur intégration.
#### Adama

