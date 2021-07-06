# Output Module API

## Introduction

This documentation describes supporting functions or methods to implement output modules (ie. XsdOutput.cpp).

## helper functions

### path helpers

Path helpers deliver strings in ImdOutput TID format.

```c++
string get_path(MMObject *o)
```
Delivers the full path string of the MMObject `o` (ie. `modelname.topicname.classname.attrname`).
   
```c++
string get_parent_path(MetaElement *e)
```
Delivers the full path string of the `o` parent object (ie. `modelname.topicname`).

### model helpers (MetaModel.h)

The MetaModel contains serveral top level (ie. direct extensions of MMObject) classes 
(ie. Model, Import, Dependency, etc.). The helper functions can be used to fill or query 
global lists that manage top level objects.

```c++
void metamodel::add_model(Model *m)
```
Adds a Model to the list of all_models.

```c++
list <Model *> metamodel::get_all_models()
```
Delivers a list of all models.

```c++
void metamodel::add_import(Import *i)
```
Adds an Import to the list of all_imports.

```c++
list <Import *> metamodel::get_all_imports()
```
Delivers a list of all model imports.
   
```c++
void metamodel::add_dependency(Dependency *d)
```
Adds a Dependency to the list of all_dependencies.

```c++
list <Dependency *> metamodel::get_all_dependencies()
```
Delivers a list of all dependencies.
   
```c++
void metamodel::add_axisspec(AxisSepec *s)
```
Adds an AxisSpec to the list of all_axisspecs.

```c++
list <AxisSpec *> metamodel::get_all_axisspecs()
```
Delivers a list of all AxisSpecs.
   
## class `metamodel::MMObject` (MetaModel.h)

```c++
string getClass()
```
Delivers the classname of the MMObject.

```c++
string getBaseClass()
```
Delivers the baseclassname of the MMObject.

```c++
bool isAbstract()
```
Is `true` if the corresponding class / structure in the interlis metamodel is abstract.

```c++
bool isSubClassOf(string classname);
```
Delivers `true` if the MMObject is an extension of class / structure with name `classname`.

```c++
MMObject* clone();
```
Clones the MMObject. The delivered object is not a deepclone, ie. attribute values of the cloned
object may point to other objects.
