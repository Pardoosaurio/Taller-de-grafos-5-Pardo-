#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include "Grafo.h"
using namespace std;

#define MAX 10005
#define Node pair<int, int>
#define INF 1 << 30

struct cmp
{
	bool operator()(const Node &a, const Node &b)
	{
		return a.second > b.second;
	}
};

vector<Node> nodo_adyacente[MAX];
int distancia_vector[MAX];
bool visitado[MAX];
priority_queue<Node, vector < Node>, cmp> Q;
int V;
int previo[MAX];

void inicializar()
{
	for (int i = 0; i < V; i++)
	{
		distancia_vector[i] = INF;
		visitado[i] = false;
		previo[i] = -1;
	}
}


void relajacion(int actual, int adyacente, int peso)
{
	if (distancia_vector[actual] + peso < distancia_vector[adyacente])
	{
		distancia_vector[adyacente] = distancia_vector[actual] + peso;
		previo[adyacente] = actual;
		Q.push(Node(adyacente, distancia_vector[adyacente]));
	}
}


void print(int destino)
{
	if (previo[destino] != -1)
		cout << previo[destino] << endl;
	cout << destino << endl;
}

template <class _TVertex, class _TEdge>
std::vector<_TEdge> Grafo <_TVertex,_TEdge>::
Dijkstra(unsigned long& start)
{
	/* crea un vector de marcas iniciandolas en false
	  su funcion es saber por cuales nodos se ha pasado
	*/
	std::vector< bool > marks(this->m_Vertices.size(), false);
	/**/
	std::vector< TDijkstraNode > q;
	/*
	vector
	*/
	std::vector<_TEdge> tree(this->m_Vertices.size(), -1);

	TDijkstraNode n;
	n.Vertex = start;
	n.Parent = start;
	n.Cost = 0;
	q.push_back(n);

	while (q.size() > 0)
	{
		// ordena menor a mayor
		std::pop_heap(q.begin(), q.end(), TDijkstraComparator());
		// se saca el menor
		n = q.back();
		// quita la raiz
		q.pop_back();

		if (marks[n.Vertex])
			continue;
		marks[n.Vertex] = true;
		tree[n.Vertex] = n.Parent;

		typename TMatrix::const_iterator mIt = this->m_Edges.find(n.Vertex);
		for (
			typename TRow::const_iterator rIt = mIt->second.begin();
			rIt != mIt->second.end();
			++rIt
			)
		{
			TDijkstraNode m;
			m.Parent = n.Vertex;
			m.Vertex = rIt->first;
			m.Cost = n.Cost + rIt->second;
			q.push_back(m);
			std::push_heap(q.begin(), q.end(), TDijkstraComparator());
		}//fin for agregar conexiones a q
	}//fin while de q
	std::vector<_TEdge> aux;
	long bb;
  aux.push_back(tree[0]);
  for (int i = 0; i < tree.size(); i++)
  {
	  bb=buscarDato(aux.back(),&tree);
	  aux.push_back(bb);
  }
  return aux;
}
void prim(int inicial2)
{
	inicializar();
	int actual, adyacente, peso;
	vector<int> adyacentes;
	vector<int> pesos;
	vector<int> visitados;
	vector<int> previos;
	int i, j, k;
	int min;
	int min_index;
	int min_peso;
	int min_previo;
	int min_visitado;
	int min_adyacente;
	int min_distancia;

	for (i = 0; i < V; i++)
	{
		adyacentes.push_back(i);
		pesos.push_back(INF);
		visitados.push_back(0);
		previos.push_back(-1);
	}
}

int main()
{
	cout << "grafo seleccionado" << endl;
	string nombreArchivo = "graph02.txt";
	ifstream archivo(nombreArchivo.c_str());
	string linea;
	do {
		cout << "\n\n";
		cout << linea << endl;
	} while ((getline(archivo, linea))

	dijkstra(1);
	prim(1);
	return 0;
}
