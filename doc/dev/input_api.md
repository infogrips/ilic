# Input Module API

## Introduction

This documentation describes supporting functions or methods to implement input modules (ie. Ili2Input.cpp).

## class `metamodel::MetaModelInput` (MetaModelInput.h)

```c++
void init_mmobject(MMObject *o,int line);
```
Initializes the MMObject o. line is the source code line of the .ili file. If
no source code line is known, -1 should be used.

```c++
void init_metaelement(MetaElement *e,int line);
```
Initializes the MetaElement e. line is the source code line of the .ili file. If
no source code line is known, -1 should be used.

```c++
void init_metaobject(ExpandebleME *e,int line);
```
Initializes the ExpandebleME e. line is the source code line of the .ili file. If
no source code line is known, -1 should be used.
