public class Atomo 
{
    public string Sigla {get; set;}
    public string X {get; set;}
    public string Y {get; set;}
    public string Z {get; set;}

    public Atomo(string sigla, string x, string y, string z)
    {
        this.Sigla = sigla;
        this.X = x;
        this.Y = y;
        this.Z = z;
    }

    public override bool Equals(object? obj)
    {
        var atomo = obj as Atomo;

        if (atomo != null)
        { 
            return this.Sigla.Equals(atomo.Sigla) && this.X.Equals(atomo.X) &&
                    this.Y.Equals(atomo.Y) && this.Z.Equals(atomo.Z);

        } else
        {
            throw new ArgumentException("Objeto não é Atomo");
        }
    }

    public override string ToString()
    {
        return "Atomo{" + "sigla=" + this.Sigla + ", eixo x=" + this.X + ", eixo y=" + this.Y + ", eixo z=" + this.Z + '}';
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Sigla,X,Y,Z);
    }

}