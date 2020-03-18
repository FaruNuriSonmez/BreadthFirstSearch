#include <stdio.h>
#include <stdbool.h>

int graph[6][6];
//Düğümlerin ziyaret edilip edilmediğini tutan değişken.
bool visited[5];
 
//Kuyruk veri yapımı bağlı listede tutacağım için struct node oluşturdum.
struct node{
    int data;
    struct node *next;
};
 
//Kuyruğun en ön ve en arka elemanları için düğüm oluşturdum.
struct node* first = NULL;
struct node* last = NULL;
 
//Düğüm oluşturan fonksiyon
struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
 
//kuyruğa eleman ekleyen fonksiyon
void enQueue(int x)
{
    struct node* newyNode = createNode(x);
    if(first == NULL)
    {
        first = newyNode;
        last = newyNode;
    }
    else
    {
        last->next = newyNode;
        last = newyNode;
    }
}
 
//kuyruktan eleman çıkaran fonksiyon
void deQueue()
{
    if(first == NULL)
    {
        printf("\n Your Queue is empty");
        return;
    }
 
    if(first->next == NULL)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        struct node* secondNode = first->next;
        free(first);
        first = secondNode;
    }
 
}
 
//kuyruk boş mu diye kontrol eden fonksiyon
bool isEmpty()
{
    if(first == NULL)
        return true;
    else
        return false;
}
 
//kuyruğun en önündeki elemanı return eden fonksiyon
int next()
{
    return first->data;
}

void BFS(int, int, QUEUE*);
BFS(indis1, indis2, *que);
void BFS(int indis1, int indis2, QUEUE *que,) 
{
    int bulundu = 0, klmSay =0, i, j, indisTMP;
    int** matris;
    QUEUE que;

    enQueue(indis1, &que);
    inQueue[indis1] = -1;
    while((isEmpty(&que) == 0) && (bulundu == 0)) 
    {
        indisTMP == deQueue(&que);
        if(indisTMP == indis2)
            bulundu = 1;
        else
        {
            for(j = 0; j< klmSay; j++)
            {
                if((matris[indisTMP][j] == 1) && (inQueue[j] == 0))
                {
                    enQueue(j, &que);
                    inQueue[j] = indisTMP;
                }
            }
        }
    }
}



void BFS(int root)
{
    int i;
    //Tüm düğümler ilk başta ziyaret edilmemiş.
    for(i = 0; i < 6; i++)
    {
        visited[i] = false;
    }
 
    //Başlangıç düğümünü ziyaret edildi kuruğa eklendi.
    visited[root]  = true;
    enQueue(root);
	
    while(isEmpty() == false)
    {
        //döngünün her adımında root değerine kuyruğun en önündeki elemanı ata
        root = next();
        printf("%d ", root);
        deQueue();
 
        //Bu döngü bir düğümün ziyaret edilmemiş komşularını kuyruğa ekliyor.
        for( i = 0; i < 6; i++)
        {
		//Eğer bir düğüm ziyaret edilmemişse ve aralarında bağlantı var ise bu
            if(visited[i] == false && graph[root][i] == 1)
            {
                visited[i] = true;
                enQueue(i);
            }
        }
    }
}
 
void readGraph()
{
    int i = 0;
    FILE *fp = fopen("matris.txt", "r");
    while(fscanf(fp, "%d %d %d %d %d %d",
                 &graph[i][0],
                 &graph[i][1],
                 &graph[i][2],
                 &graph[i][3],
                 &graph[i][4],
                 &graph[i][5]) !=EOF){
        i = i + 1;
    }
 
}
 
int main()
{
    readGraph();
    BFS(2);
    return 0;
}
