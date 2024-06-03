using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fila
{
    internal class Aluno
    {
        public int Matricula { get; set; }
        public string Nome { get; set; }

        public Aluno(int matricula, string nome)
        {
            this.Matricula= matricula;
            this.Nome = nome;
        }
        
        public override string ToString()
        {
            return "Aluno [matricula=" + Matricula + ", nome=" + Nome + "]";
        }

        public override bool Equals(object obj)
        {
            Aluno other = (Aluno)obj;
            if (Matricula != other.Matricula)
                return false;
            if (!Nome.Equals(other.Nome))
                return false;
            return true;
        }
    }
}
