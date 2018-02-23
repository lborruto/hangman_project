#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char **argv)
{
    const int FAUX_MAX = 500; //maximum de tentative
    vector<string> words; //vecteur pour ajouter nos mots
    //ici les mots
    
    words.push_back("KENTUCKY FRIED CHICKEN CEST LA VIE");
    words.push_back("LE CESI CEST POURRIS ?");
    words.push_back("LE CESI CEST LA VIEEEE");
    words.push_back("5000 EUROS PAR ANS POUR DES PUTAIN DE TABLES SERIEUSEMENT ??!");
    words.push_back("QUI VA VRAIMENT DEVINER SES MOTS ?");
    words.push_back("QUI VA VRAIMENT DEVINER CA EN 5 TENTATIVE ?");
    words.push_back("JE DONNE 5 EUROS A CELUI QUI TROUVE CA EN 5 TENTATIVE SANS AVOIR LU LE CODE");
    words.push_back("CEST PAS OUF COMME CODE MAIS BON CEST DEJA PAS MAL ET PUIS SA FONCTIONNE ALORS QUI VA EN AVOIR QUELQUE CHOSE A FAIRE ?");
    words.push_back("EMMA SI TU LIS CA MET MOI UN A JE DONNE DES SOUS SI JAMAIS CONTACTE MOI SUR LE DARKWEB");
    
    srand(static_cast<unsigned int>(time(0))); //seed pour chiffre aléatoire
    random_shuffle(words.begin(), words.end()); //aléatoire pour les mots
    const string MOT_A_DEVINER = words[0]; //mot a deviner
    string soFar(MOT_A_DEVINER.size(), '-'); //fichier string avec '-'
    string usedLetters = "";
    int wrong = 0; //pour compter les mots faux
    
    cout << "BIENVENUE AU JEU DU PENDU LE PLUS DUR DU MONDE ! \n@LBORRUTO";
    
    //on va ajouter la principale boucle du jeu
    while ((wrong < FAUX_MAX) && (soFar != MOT_A_DEVINER))
    {
        cout << "\n\nVOUS AVEZ " << (FAUX_MAX - wrong) << " TENTATIVES RESTANTES. \n";
        cout << "\n\nVOUS AVEZ DEJA UTILISER SES LETTRES : " << usedLetters << endl;
        cout << "\n\nLE MOT RESSEMBLE A CA :\n" << soFar << endl;
        
        char guess;
        cout << "\n\nENTREZ VOS PROPOSITIONS: ";
        cin >> guess;
        guess = toupper(guess);
        
        while (usedLetters.find(guess) != string::npos) //quand le joueur entre quelque chose qu'il a déja rentrer, la boucle continue
        {
            cout << "\nVOUS AVEZ DEJA PROPOSER " << guess << endl;
            cout << "ENTREZ VOS PROPOSITIONS: ";
            cin >> guess;
            guess = toupper(guess);
        }
        
        usedLetters += guess;
        if (MOT_A_DEVINER.find(guess) != string::npos)
        {
            cout << "BIEN ! " << guess << " ETAIS LE BON MOT!\n";
            for (int i = 0; i < MOT_A_DEVINER.length(); i++)
            {
                if (MOT_A_DEVINER[i] == guess)
                {
                    soFar[i] = guess;
                }
                
                else
                {
                    cout << "DESOLE, " << guess << " N'EST PAS DANS LA LISTE.\n";
                    ++wrong;
                }
            }
            
            if (wrong == FAUX_MAX)
            {
                cout << "\n\nGAME OVER !";
            }
            else
            {
                cout << "\n\nTU AS PAS TROUVE !";
            }
            
            cout << "\n\nLE MOT ETAIS: " << MOT_A_DEVINER << endl;
            cout << "\n\n";
            
        }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
