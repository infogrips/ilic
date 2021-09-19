#include "antlr4-runtime.h"
#include "../parser/generated/Ili1ParserBaseVisitor.h"

#include <string>

using namespace std;

namespace input {
   
   void parseIli1(string input);

   class Ili1Input : public parser::Ili1ParserBaseVisitor {
   public:

      antlrcpp::Any Ili1Input::visitInterlis1Def(parser::Ili1Parser::Interlis1DefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitModelDef(parser::Ili1Parser::ModelDefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitTopicDef(parser::Ili1Parser::TopicDefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitTableDef(parser::Ili1Parser::TableDefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDecimal(parser::Ili1Parser::DecimalContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDerivatives(parser::Ili1Parser::DerivativesContext *ctx) override;
      antlrcpp::Any Ili1Input::visitFormatEncoding(parser::Ili1Parser::FormatEncodingContext *ctx) override;
      antlrcpp::Any Ili1Input::visitFont(parser::Ili1Parser::FontContext *ctx) override;
      antlrcpp::Any Ili1Input::visitCode(parser::Ili1Parser::CodeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitAttribute(parser::Ili1Parser::AttributeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitIdentifications(parser::Ili1Parser::IdentificationsContext *ctx) override;
      antlrcpp::Any Ili1Input::visitIdentification(parser::Ili1Parser::IdentificationContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDomainDefs(parser::Ili1Parser::DomainDefsContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDomainDef(parser::Ili1Parser::DomainDefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitType(parser::Ili1Parser::TypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitBaseType(parser::Ili1Parser::BaseTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitCoord2(parser::Ili1Parser::Coord2Context *ctx) override;
      antlrcpp::Any Ili1Input::visitCoord3(parser::Ili1Parser::Coord3Context *ctx) override;
      antlrcpp::Any Ili1Input::visitNumericRange(parser::Ili1Parser::NumericRangeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDim1Type(parser::Ili1Parser::Dim1TypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDim2Type(parser::Ili1Parser::Dim2TypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitAngleType(parser::Ili1Parser::AngleTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitTextType(parser::Ili1Parser::TextTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitDateType(parser::Ili1Parser::DateTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitEnumerationType(parser::Ili1Parser::EnumerationTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitEnumElement(parser::Ili1Parser::EnumElementContext *ctx) override;
      antlrcpp::Any Ili1Input::visitHorizAlignment(parser::Ili1Parser::HorizAlignmentContext *ctx) override;
      antlrcpp::Any Ili1Input::visitVertAlignment(parser::Ili1Parser::VertAlignmentContext *ctx) override;
      antlrcpp::Any Ili1Input::visitLineType(parser::Ili1Parser::LineTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitAreaType(parser::Ili1Parser::AreaTypeContext *ctx) override;
      antlrcpp::Any Ili1Input::visitForm(parser::Ili1Parser::FormContext *ctx) override;
      //antlrcpp::Any Ili1Input::visitLineForm(parser::Ili1Parser::LineFormContext *ctx) override;
      antlrcpp::Any Ili1Input::visitIntersectionDef(parser::Ili1Parser::IntersectionDefContext *ctx) override;
      antlrcpp::Any Ili1Input::visitControlPoints(parser::Ili1Parser::ControlPointsContext *ctx) override;
      antlrcpp::Any Ili1Input::visitLineAttributes(parser::Ili1Parser::LineAttributesContext *ctx) override;

   };

};
