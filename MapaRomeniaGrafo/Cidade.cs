using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapaRomeniaGrafo
{
    class Cidade
    {
        public String nome;
        public int estimativa;

        public Cidade(String nome, int estimativa)
        {
            this.nome = nome;
            this.estimativa = estimativa;
        }

        public override String ToString()
        {
            return this.nome + ". Custo estimado: " + this.estimativa;
        }

    }
}
