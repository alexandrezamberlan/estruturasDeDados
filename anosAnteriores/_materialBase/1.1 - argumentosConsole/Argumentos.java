public class Argumentos {
    public static void main(String [] vetorArgumentos) {
        
        try {            
            System.out.println("Quantidade de argumentos: " + vetorArgumentos.length);
            for (int index = 0; index < vetorArgumentos.length; index++) {
                System.out.println("Argumento " + index + ": " + vetorArgumentos[index]);
            }
        } catch (Exception e) {
            // TODO: handle exception
        }

    }
}