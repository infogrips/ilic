#include "InterlisModel.h"
#include "../../util/Logger.h"

using namespace input;

string input::getInterlisModel23()
{
   
   string source = "";
   
   source += "INTERLIS 2.3;\n";
   source += "\n";
   source += "CONTRACTED TYPE MODEL ILIC_INTERLIS (en) AT \"http://www.interlis.ch/\" VERSION \"2005-06-16\" =\n";
   source += "\n";
   source += "   UNIT\n";
   source += "      ANYUNIT (ABSTRACT);\n";
   source += "      DIMENSIONLESS (ABSTRACT);\n";
   source += "      LENGTH (ABSTRACT);\n";
   source += "      MASS (ABSTRACT);\n";
   source += "      TIME (ABSTRACT);\n";
   source += "      ELECTRIC_CURRENT (ABSTRACT);\n";
   source += "      TEMPERATURE (ABSTRACT);\n";
   source += "      AMOUNT_OF_MATTER (ABSTRACT);\n";
   source += "      ANGLE (ABSTRACT);\n";
   source += "      SOLID_ANGLE (ABSTRACT);\n";
   source += "      LUMINOUS_INTENSITY (ABSTRACT);\n";
   source += "      MONEY (ABSTRACT);\n";
   source += "      METER [m] EXTENDS LENGTH;\n";
   source += "      KILOGRAM [kg] EXTENDS MASS;\n";
   source += "      SECOND [s] EXTENDS TIME;\n";
   source += "      AMPERE [A] EXTENDS ELECTRIC_CURRENT;\n";
   source += "      DEGREE_KELVIN [K] EXTENDS TEMPERATURE;\n";
   source += "      MOLE [mol] EXTENDS AMOUNT_OF_MATTER;\n";
   source += "      RADIAN [rad] EXTENDS ANGLE;\n";
   source += "      STERADIAN [sr] EXTENDS SOLID_ANGLE;\n";
   source += "      CANDELA [cd] EXTENDS LUMINOUS_INTENSITY;\n";
   source += "\n";
   source += "   DOMAIN\n";
   source += "      ILIC_URI (FINAL) = TEXT*1023;\n";
   source += "      ILIC_NAME (FINAL) = TEXT*255;\n";
   source += "      INTERLIS_1_DATE (FINAL) = TEXT*8;\n";
   source += "      BOOLEAN (FINAL) = (\n";
   source += "         false,\n";
   source += "         true) ORDERED;\n";
   source += "      HALIGNMENT (FINAL) = (\n";
   source += "         Left,\n";
   source += "         Center,\n";
   source += "         Right) ORDERED;\n";
   source += "      VALIGNMENT (FINAL) = (\n";
   source += "         Top,\n";
   source += "         Cap,\n";
   source += "         Half,\n";
   source += "         Base,\n";
   source += "         Bottom) ORDERED;\n";
   source += "      ANYOID = OID ANY;\n";
   source += "      I32OID = OID 0 .. 2147483647;\n";
   source += "      STANDARDOID = OID TEXT*16;\n";
   source += "      UUIDOID = OID TEXT*36;\n";
   source += "      LineCoord (ABSTRACT) = COORD NUMERIC, NUMERIC;\n";
   source += "\n";
   source += "   FUNCTION myClass (Object: ANYSTRUCTURE): STRUCTURE;\n";
   source += "   FUNCTION isSubClass (potSubClass: STRUCTURE; potSuperClass: STRUCTURE):BOOLEAN;\n";
   source += "   FUNCTION isOfClass (Object: ANYSTRUCTURE; Class: STRUCTURE): BOOLEAN;\n";
   source += "   FUNCTION elementCount (bag: BAG OF ANYSTRUCTURE): NUMERIC;\n";
   source += "   FUNCTION objectCount (Objects: OBJECTS OF ANYCLASS): NUMERIC;\n";
   source += "   FUNCTION len (TextVal: TEXT): NUMERIC;\n";
   source += "   FUNCTION lenM (TextVal: MTEXT): NUMERIC;\n";
   source += "   FUNCTION trim (TextVal: TEXT): TEXT;\n";
   source += "   FUNCTION trimM (TextVal: MTEXT): MTEXT;\n";
   source += "   FUNCTION isEnumSubVal (SubVal: ENUMTREEVAL; NodeVal: ENUMTREEVAL): BOOLEAN;\n";
   source += "   FUNCTION inEnumRange (\n";
   source += "      Enum: ENUMVAL;\n";
   source += "      MinVal: ENUMTREEVAL;\n";
   source += "      MaxVal: ENUMTREEVAL\n";
   source += "   ): BOOLEAN;\n";
   source += "   FUNCTION convertUnit (from: NUMERIC): NUMERIC;\n";
   source += "!!   FUNCTION areAreas (\n";
   source += "!!    Objects: OBJECTS OF ANYCLASS;\n";
   source += "!!      SurfaceBag: ATTRIBUTE OF @ Objects RESTRICTION (BAG OF ANYSTRUCTURE);\n";
   source += "!!      SurfaceAttr: ATTRIBUTE OF @ SurfaceBag RESTRICTION (SURFACE)\n";
   source += "!!   ): BOOLEAN;\n";
   source += "   \n";
   source += "   CLASS ILIC_METAOBJECT (ABSTRACT) =\n";
   source += "      Name: MANDATORY ILIC_NAME;\n";
   source += "      UNIQUE Name;\n";
   source += "   END ILIC_METAOBJECT;\n";
   source += "   \n";
   source += "   CLASS METAOBJECT_TRANSLATION =\n";
   source += "      Name: MANDATORY ILIC_NAME;\n";
   source += "      NameInBaseLanguage: MANDATORY ILIC_NAME;\n";
   source += "      UNIQUE Name;\n";
   source += "      UNIQUE NameInBaseLanguage;\n";
   source += "   END METAOBJECT_TRANSLATION;\n";
   source += "\n";
   source += "   STRUCTURE AXIS =\n";
   source += "      PARAMETER\n";
   source += "         Unit: NUMERIC [ANYUNIT];\n";
   source += "   END AXIS;\n";
   source += "   \n";
   source += "   CLASS ILIC_REFSYSTEM (ABSTRACT) EXTENDS ILIC_METAOBJECT =\n";
   source += "   END ILIC_REFSYSTEM;\n";
   source += "   \n";
   source += "   CLASS COORDSYSTEM (ABSTRACT) EXTENDS ILIC_REFSYSTEM =\n";
   source += "      ATTRIBUTE\n";
   source += "         Axis: LIST {1..3} OF AXIS;\n";
   source += "   END COORDSYSTEM;\n";
   source += "   \n";
   source += "   CLASS SCALSYSTEM (ABSTRACT) EXTENDS ILIC_REFSYSTEM =\n";
   source += "      PARAMETER\n";
   source += "         Unit: NUMERIC [ANYUNIT];\n";
   source += "   END SCALSYSTEM;\n";
   source += "   \n";
   source += "   CLASS ILIC_SIGN (ABSTRACT) EXTENDS ILIC_METAOBJECT =\n";
   source += "      PARAMETER\n";
   source += "         Sign: METAOBJECT;\n";
   source += "   END ILIC_SIGN;\n";
   source += "   \n";
   source += "   TOPIC TIMESYSTEMS =\n";
   source += "   \n";
   source += "      CLASS CALENDAR EXTENDS SCALSYSTEM =\n";
   source += "         PARAMETER\n";
   source += "            Unit(EXTENDED): NUMERIC [TIME];\n";
   source += "      END CALENDAR;\n";
   source += "      \n";
   source += "      CLASS TIMEOFDAYSYS EXTENDS SCALSYSTEM =\n";
   source += "         PARAMETER\n";
   source += "            Unit(EXTENDED): NUMERIC [TIME];\n";
   source += "      END TIMEOFDAYSYS;\n";
   source += " \n";
   source += "   END TIMESYSTEMS;\n";
   source += " \n";
   source += "   UNIT\n";
   source += "      Minute [min] = 60 [s];\n";
   source += "      Hour [h] = 60 [min];\n";
   source += "      Day [d] = 24 [h];\n";
   source += "      Month [M] EXTENDS TIME;\n";
   source += "      Year [Y] EXTENDS TIME;\n";
   source += "      \n";
   source += "      REFSYSTEM BASKET BaseTimeSystems ~ TIMESYSTEMS\n";
   source += "         OBJECTS OF CALENDAR: GregorianCalendar\n";
   source += "         OBJECTS OF TIMEOFDAYSYS: UTC;\n";
   source += "\n";
   source += "      STRUCTURE TimeOfDay (ABSTRACT) =\n";
   source += "         Hours: 0 .. 23 CIRCULAR [h];\n";
   source += "         CONTINUOUS SUBDIVISION Minutes: 0 .. 59 CIRCULAR [min];\n";
   source += "         CONTINUOUS SUBDIVISION Seconds: 0.000 .. 59.999 CIRCULAR [s];\n";
   source += "      END TimeOfDay;\n";
   source += "      \n";
   source += "      STRUCTURE UTC EXTENDS TimeOfDay =\n";
   source += "         Hours(EXTENDED): 0 .. 23 {UTC};\n";
   source += "      END UTC;\n";
   source += "\n";
   source += "   DOMAIN\n";
   source += "      GregorianYear = 1582 .. 2999 [Y] {GregorianCalendar};\n";
   source += " \n";
   source += "   STRUCTURE GregorianDate =\n";
   source += "      Year: GregorianYear;\n";
   source += "      SUBDIVISION Month: 1 .. 12 [M];\n";
   source += "      SUBDIVISION Day: 1 .. 31 [d];\n";
   source += "   END GregorianDate;\n";
   source += "\n";
   source += "   STRUCTURE GregorianDateTime EXTENDS GregorianDate =\n";
   source += "      SUBDIVISION Hours: 0 .. 23 CIRCULAR [h] {UTC};\n";
   source += "      CONTINUOUS SUBDIVISION Minutes: 0 .. 59 CIRCULAR [min];\n";
   source += "      CONTINUOUS SUBDIVISION Seconds: 0.000 .. 59.999 CIRCULAR [s];\n";
   source += "   END GregorianDateTime;\n";
   source += "\n";
   source += "   DOMAIN XMLTime = FORMAT BASED ON \n";
   source += "      UTC ( Hours/2 \":\" Minutes \":\" Seconds );\n";
   source += "   DOMAIN XMLDate = FORMAT BASED ON \n";
   source += "      GregorianDate ( Year \"-\" Month \"-\" Day );\n";
   source += "   DOMAIN XMLDateTime EXTENDS XMLDate = FORMAT BASED ON \n";
   source += "      GregorianDateTime (INHERITANCE \"T\" Hours/2 \":\" Minutes \":\" Seconds);\n";
   source += "\n";
   source += "   STRUCTURE LineSegment (ABSTRACT) =\n";
   source += "      SegmentEndPoint: MANDATORY LineCoord;\n";
   source += "   END LineSegment;\n";
   source += "   \n";
   source += "   STRUCTURE StartSegment (FINAL) EXTENDS LineSegment =\n";
   source += "   END StartSegment;\n";
   source += "   \n";
   source += "   STRUCTURE StraightSegment (FINAL) EXTENDS LineSegment =\n";
   source += "   END StraightSegment;\n";
   source += "\n";
   source += "   STRUCTURE ArcSegment (FINAL) EXTENDS LineSegment =\n";
   source += "      ArcPoint: MANDATORY LineCoord;\n";
   source += "      Radius: NUMERIC [LENGTH];\n";
   source += "   END ArcSegment;\n";
   source += "   \n";
   source += "   STRUCTURE SurfaceEdge =\n";
   source += "      Geometry: DIRECTED POLYLINE;\n";
   source += "      LineAttrs: ANYSTRUCTURE;\n";
   source += "   END SurfaceEdge;\n";
   source += "\n";
   source += "   STRUCTURE SurfaceBoundary =\n";
   source += "      Lines: LIST OF SurfaceEdge;\n";
   source += "   END SurfaceBoundary;\n";
   source += "\n";
   source += "   STRUCTURE LineGeometry =\n";
   source += "      Segments: LIST OF LineSegment;\n";
   source += "   !!MANDATORY CONSTRAINT isOfClass (Segments[FIRST],StartSegment);\n";
   source += "   END LineGeometry;\n";
   source += "\n";
   source += "END ILIC_INTERLIS.\n";

   return source;

}
