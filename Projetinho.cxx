#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define lista std::vector
#define pularLinha "\n"
#define Retorne return

class Personagem {
private:
    std::string nome;
    int idade;
    double altura;
    double peso;

public:
    // Construtor
    Personagem(std::string n, int i, double a, double p) {
        nome = n;
        idade = i;
        altura = a;
        peso = p;
    }

    // Setters
    void setNome(std::string n) {
        nome = n;
    }

    void setIdade(int i) {
        idade = i;  // Atribuindo o valor de 'i' a 'idade'
    }

    void setAltura(double a) {
        altura = a;
    }

    void setPeso(double p) {
        peso = p;
    }

    // Getters
    std::string getNome() {
        return nome;
    }

    int getIdade() {
        return idade;
    }

    double getAltura() {
        return altura;
    }

    double getPeso() {
        return peso;
    }

    // Método para exibir informações do personagem
    void informacaoPessoa() {
        std::cout << "\nNome: " << getNome() << "\n";
        std::cout << "Idade: " << getIdade() << "\n";
        std::cout << "Altura: " << getAltura() << " m\n";  // Unidade de altura
        std::cout << "Peso: " << getPeso() << " kg\n";
              // Unidade de peso

    }
};



void DesenhaQuadrado() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5f, 0.5f);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.5f, 0.5f);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.5f, -0.5f);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(-0.5f, -0.5f);
    glEnd();

    glFlush();
}

void DesenhaTriangulo() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.5f, -0.5f);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}

void DesenhaRetangulo() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.0f, 1.0f);
        glVertex2f(-0.7f, 0.3f);
        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.7f, -0.3f);
        glVertex2f(-0.7f, -0.3f);
    glEnd();

    glFlush();
}

void DesenhaCirculo() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float raio = 0.5f;
    int numSegments = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = raio * cosf(theta);
        float y = raio * sinf(theta);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    typedef int inteiro;

    inteiro tam;
    inteiro opcao;

    do {
        std::cout << "\n***************************" << pularLinha;
        std::cout << "BEM-VINDO AO PROGRAMA DE DESENHOS GEOMÉTRICOS";
        std::cout << "\nDigite Uma Opção: ";
        std::cout << "\n1: Ver Quadrado \n2: Ver Triângulo \n3: Ver Retângulo \n4: Ver Círculo \n5: Ver Números Pares \n6: Digitar Nomes \n7: Raiz Quadrada \n8: Elevar Um Número Ao Outro \n9: Tabuada \n10: Cadastrar Personagem \n11: Sair\n";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            glutInit(&argc, argv);
            glutInitWindowSize(500, 500);
            glutInitWindowPosition(600, 600);
            glutInitDisplayMode(GLUT_RGB);
            glutCreateWindow("Quadrado");
            glutDisplayFunc(DesenhaQuadrado);
            glutMainLoop();
            break;

        case 2:
            glutInit(&argc, argv);
            glutInitWindowSize(500, 500);
            glutInitWindowPosition(600, 600);
            glutInitDisplayMode(GLUT_RGB);
            glutCreateWindow("Triângulo");
            glutDisplayFunc(DesenhaTriangulo);
            glutMainLoop();
            break;

        case 3:
            glutInit(&argc, argv);
            glutInitWindowSize(500, 500);
            glutInitWindowPosition(600, 600);
            glutInitDisplayMode(GLUT_RGB);
            glutCreateWindow("Retângulo");
            glutDisplayFunc(DesenhaRetangulo);
            glutMainLoop();
            break;

        case 4:
            glutInit(&argc, argv);
            glutInitWindowSize(500, 500);
            glutInitWindowPosition(600, 600);
            glutInitDisplayMode(GLUT_RGB);
            glutCreateWindow("Círculo");
            glutDisplayFunc(DesenhaCirculo);
            glutMainLoop();
            break;

        case 5: {
            std::cout << "\nDigite O Tamanho Dos Números: " << pularLinha;
            std::cin >> tam;

            std::vector<inteiro> numbers(tam);

            std::cout << "\nDigite os números:\n";
            for (inteiro i = 0; i < tam; i++) {
                std::cin >> numbers[i];
            }

            std::cout << "\nNÚMEROS PARES:\n";
            for (inteiro i = 0; i < tam; i++) {
                if (numbers[i] % 2 == 0) {
                    std::cout << numbers[i] << pularLinha;
                }
            }
            break;
        }

        case 6: {
            lista<std::string> names(5);

            std::cout << "\nDigite 5 Nomes: " << pularLinha;
            for (inteiro i = 0; i < 5; i++) {
                std::cin >> names[i];
            }

            std::cout << "\nNOMES DIGITADOS:\n";
            for (const std::string& name : names) {
                std::cout << name << pularLinha;
            }
            break;
        }

        case 7: {
            int x, y;
            std::cout << "Digite dois números para calcular a raiz quadrada: ";
            std::cin >> x >> y;
            std::cout << "\nRaiz de " << x << ": " << sqrt(x) << pularLinha;
            std::cout << "\nRaiz de " << y << ": " << sqrt(y) << pularLinha;
            break;
        }

        case 8: {
            int base, expoente;
            std::cout << "Digite a base: ";
            std::cin >> base;
            std::cout << "Digite o expoente: ";
            std::cin >> expoente;
            std::cout << "\n" << base << " elevado a " << expoente << " é: " << pow(base, expoente) << pularLinha;
            break;
        }

        case 9: {
            int numero;
            std::cout << "Digite um número para ver sua tabuada: ";
            std::cin >> numero;
            for (int i = 1; i <= 10; ++i) {
                std::cout << numero << " x " << i << " = " << numero * i << pularLinha;
            }
            break;
        }

        case 10:{
                std::string nome;
                int idade;
                double altura;
                double peso;

                std::cout << "\nDigite o nome: ";
                std::cin >> nome;
                std::cout << "\nDigite a idade: ";
                std::cin >> idade;
                std::cout << "\nDigite a altura (em metros): ";
                std::cin >> altura;
                std::cout << "\nDigite o peso (em quilos): ";
                std::cin >> peso;

                // Cria um objeto Personagem com os dados informados
                Personagem personagem(nome, idade, altura, peso);

                personagem.informacaoPessoa(); // Exibe as informações do personagem

                 if(peso>=90 || altura>= 1.90){
                std::cout<<"\nVocê Está muito acima do Peso!"<<"\n";
              }
              if(idade<=0){
                std::cout<<"\nIdadeInexistente!"<<"\n";
              }
              else{
               std::cout<<"\nParabens! Peso Ideal"<<"\n";
              }

                break;
            }


        case 11:
            std::cout << "\nSAIU" << pularLinha;
            return 0;

        default:
            std::cout << "Opção inválida!" << pularLinha;
            break;
        }

    } while (true);

    Retorne 0;
}
