#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

struct document doc;

struct document get_document(char* text) {
    struct document d;
    d.paragraph_count = 0;
    d.data = malloc(sizeof(struct paragraph) * 100);
    
    char *paragraph_token, *sentence_token, *word_token;
    char *text_copy = strdup(text);
    paragraph_token = strtok(text_copy, "\n");
    
    while (paragraph_token) {
        struct paragraph *p = &d.data[d.paragraph_count];
        p->sentence_count = 0;
        p->data = malloc(sizeof(struct sentence) * 100);
        
        char *paragraph_copy = strdup(paragraph_token);
        sentence_token = strtok(paragraph_copy, ".");
        
        while (sentence_token) {
            struct sentence *s = &p->data[p->sentence_count];
            s->word_count = 0;
            s->data = malloc(sizeof(struct word) * 100);
            
            char *sentence_copy = strdup(sentence_token);
            word_token = strtok(sentence_copy, " ");
            
            while (word_token) {
                s->data[s->word_count].data = strdup(word_token);
                s->word_count++;
                word_token = strtok(NULL, " ");
            }
            free(sentence_copy);
            p->sentence_count++;
            sentence_token = strtok(NULL, ".");
        }
        free(paragraph_copy);
        d.paragraph_count++;
        paragraph_token = strtok(NULL, "\n");
    }
    free(text_copy);
    return d;
}

struct paragraph get_paragraph(int paragraph_number) {
    return doc.data[paragraph_number - 1];
}

struct sentence get_sentence(int paragraph_number, int sentence_number) {
    return doc.data[paragraph_number - 1].data[sentence_number - 1];
}

struct word get_word(int paragraph_number, int sentence_number, int word_number) {
    return doc.data[paragraph_number - 1].data[sentence_number - 1].data[word_number - 1];
}

void print_paragraph(struct paragraph p) {
    for (int i = 0; i < p.sentence_count; i++) {
        struct sentence s = p.data[i];
        for (int j = 0; j < s.word_count; j++) {
            printf("%s", s.data[j].data);
            if (j < s.word_count - 1) printf(" ");
        }
        if (i < p.sentence_count - 1) printf(".");
    }
    printf("\n");
}

void print_sentence(struct sentence s) {
    for (int i = 0; i < s.word_count; i++) {
        printf("%s", s.data[i].data);
        if (i < s.word_count - 1) printf(" ");
    }
    printf("\n");
}

void print_word(struct word w) {
    printf("%s\n", w.data);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    char text[10000] = "";
    for (int i = 0; i < n; i++) {
        char line[1000];
        fgets(line, sizeof(line), stdin);
        strcat(text, line);
    }
    
    doc = get_document(text);
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int p;
            scanf("%d", &p);
            print_paragraph(get_paragraph(p));
        } else if (type == 2) {
            int p, s;
            scanf("%d %d", &p, &s);
            print_sentence(get_sentence(p, s));
        } else if (type == 3) {
            int p, s, w;
            scanf("%d %d %d", &p, &s, &w);
            print_word(get_word(p, s, w));
        }
    }
    return 0;
}
