#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dnacount() {
	//upper limit for input sequence is 5 kb
	char DNA[5000];
	int A = 0;
	int T = 0;
	int C = 0;
	int G = 0;
	printf("Enter DNA sequence: \n");
	scanf("%s", DNA);

	for (int i = 0; i < strlen(DNA); i++){
		if (DNA[i] == 65 || DNA[i] == 97){
			A++;
		} else if (DNA[i] == 84 || DNA[i] == 116){
			T++;
		} else if (DNA[i] == 67 || DNA[i] == 99){
			C++;
		} else if (DNA[i] == 71 || DNA[i] == 103){
			G++;
		} else{
			printf("invalid character in sequence, please provide only ATCG\n");
			exit(1);
		}

	}
	printf("Sequence Length of %zu\n", strlen(DNA));
	printf("A's in sequence %d\n",A);
	printf("T's in sequence %d\n",T);
	printf("C's in sequence %d\n",C);
	printf("G's in sequence %d\n",G);
	return;

}

void GC(){
	char DNA[5000];
	int G = 0;
	int C = 0;
	printf("Enter DNA sequence: \n");
	scanf("%s", DNA);
	for (int i = 0; i < strlen(DNA); i++){
		if (DNA[i] == 67 || DNA[i] == 99){
			C++;
		} else if (DNA[i] == 71 || DNA[i] == 103){
			G++;

		} 
	}
	int GC = G + C;
	float GCcontent = (float)GC/strlen(DNA);
	printf("Total Sequence Length is %zu\n",strlen(DNA));
	printf("GC Content is %f\n",GCcontent);
	return;
}

void transcribe() {
	//upper limit for input sequence is 5 kb
	char DNA[5000];
	printf("Enter DNA sequence: \n");
	scanf("%s", DNA);
	for (int i = 0; i < strlen(DNA); i++){
		if (DNA[i] == 84 || DNA[i] == 117){
			DNA[i]++;
		} else if (DNA[i] == 67 || DNA[i] == 99){
			continue;
		} else if (DNA[i] == 71 || DNA[i] == 103){
			continue;
		} else if (DNA[i] == 65 || DNA[i] == 97){
			continue;
		} else {
			printf("invalid character in sequence, please provide only ATCG\n");
			exit(1);
		}
	}
	
	printf("Transcribed sequence is %s\n",DNA);
	return;
}

void complement(){
	char DNA[5000];
	printf("Enter DNA sequence: \n");
	scanf("%s", DNA);
	for(char *p = DNA; *p !='\0'; p++){
		if (*p == 'A'){
			*p = 'T';
		} else if (*p == 'T'){
			*p ='A';
		} else if (*p =='C') {
			*p = 'G';
		} else if (*p == 'G') {
			*p = 'C';
		} else {
			printf("invalid character, provide only ATCG");
			exit(1);

		}
	}

	printf("complement sequence is %s\n", DNA);
	return;
}

// Function to reverse a string
void reverse(char str[]){
    size_t left = 0;
    size_t right = strlen(str);

    // Swap characters from both ends
    while (left < right){
        right--;

        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
    }
}

void revcomp(){
	char DNA[5000];
	printf("Enter DNA sequence: \n");
	scanf("%s", DNA);
	for(char *p = DNA; *p !='\0'; p++){
		if (*p == 'A'){
			*p = 'T';
		} else if (*p == 'T'){
			*p ='A';
		} else if (*p =='C') {
			*p = 'G';
		} else if (*p == 'G') {
			*p = 'C';
		} else {
			printf("invalid character, provide only ATCG");
			exit(1);

		}
	}
	reverse(DNA);
	printf("reverse complement sequence is %s\n", DNA);
	return;
}





int main(){
	int choice;
	printf("Select which function you'd like to use\n");
	printf("1.DNAcount\n2.GC content\n3.Transcribe\n4.Complement\n5.Reverse Complement\n");
	scanf("%i", &choice);
	switch (choice) {
	  case 1:
	    dnacount();
	    break;
	  case 2:
	    GC();
	    break;
	  case 3:
	    transcribe();
	    break;
	  case 4:
	    complement();
	    break;
	  case 5:
	    revcomp();
	    break;
	}


	
}

