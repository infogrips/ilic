# ilic API

## Introduction

This documentation describes supporting functions or methods to implement output modules (ie. XsdOutput.cpp).

## helper functions

### model helpers

```c++
list <Model *> metamodel::get_all_models()
```
Delivers a list of all compiled models.

```c++
list <Model *> metamodel::get_all_imports()
```
Delivers a list of all model imports.
   
### path helpers

```c++
string get_path(MMObject *o)
```
Delivers the full path string of the MMObject `o` (ie. `modelname.topicname.classname.attrname`).
   
```c++
string get_parent_path(MetaElement *e)
```
Delivers the full path string of the `o` parent object (ie. `modelname.topicname`).

## class `metamodel::MMObject`

```c++
string getClass()
```
Delivers the classname of the MMObject.

```c++
string getBaseClass()
```
Delivers the baseclassname of the MMObject.

```c++
string getBaseClass()
```
Delivers the baseclassname of the MMObject.

```c++
bool isAbstract()
```
Delivers `true` if the corresponding class / structure in the interlis metamodel is abstract.

```c++
bool isInstanceOf(string classname);
```
Delivers `true` if the MMObject is an extension of class / structure with name `classname`.
