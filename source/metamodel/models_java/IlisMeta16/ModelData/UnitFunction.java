package ch.interlis.models.IlisMeta16.ModelData;
public class UnitFunction extends ch.interlis.models.IlisMeta16.ModelData.Factor
{
  public final static String tag= "IlisMeta16.ModelData.UnitFunction";
  public UnitFunction() {
    super();
  }
  public String getobjecttag() {
    return tag;
  }
  public final static String tag_Explanation="Explanation";
  public String getExplanation() {
    String value=getattrvalue("Explanation");
    return value;
  }
  public void setExplanation(String value) {
    setattrvalue("Explanation", value);
  }
}
