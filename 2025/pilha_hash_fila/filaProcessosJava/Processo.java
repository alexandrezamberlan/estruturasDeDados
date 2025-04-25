
import java.util.Objects;

public class Processo {	
	int id;
	String descricao;
	
	/***
	 * construtor de processo
	 * @param id - inteiro com numero aleatorio entre 1 e 1000
	 * @param descricao - explicação do processo
	 */
	public Processo(int id, String descricao) {
		super();
		this.id = id;
		this.descricao = descricao;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	@Override
	public String toString() {
		return "Processo [id=" + id + ", descricao=" + descricao + "]";
	}


	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Processo other = (Processo) obj;
		return id == other.id;
	}
}
