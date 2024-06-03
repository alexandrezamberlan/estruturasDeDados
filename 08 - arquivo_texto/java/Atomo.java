public class Atomo {
    String sigla;
    String x;
    String y;
    String z;
    
    public String getSigla() {
        return sigla;
    }
    public void setSigla(String sigla) {
        this.sigla = sigla;
    }
    public String getX() {
        return x;
    }
    public void setX(String x) {
        this.x = x;
    }
    public String getY() {
        return y;
    }
    public void setY(String y) {
        this.y = y;
    }
    public String getZ() {
        return z;
    }
    public void setZ(String z) {
        this.z = z;
    }
    public Atomo(String sigla, String x, String y, String z) {
        this.sigla = sigla;
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public int hashCode() {        
        return (this.sigla + this.x + this.y + this.z).hashCode();
    }
    @Override
    public boolean equals(Object obj) {   
        Atomo other = (Atomo) obj;     
        return this.sigla.equals(other.sigla) && this.x.equals(other.x) 
                   && this.y.equals(other.y) && this.z.equals(other.z);       
    }
    @Override
    public String toString() {
        return "Atomo [sigla=" + sigla + ", x=" + x + ", y=" + y + ", z=" + z + "]";
    }
}
