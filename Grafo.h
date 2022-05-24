#ifndef __Grafo__H__
#define __Grafo__H__

#include <queue>
#include <string>
#include <map>
#include <stack>


  class Grafo
  {
struct TDijkstraNode
	  {
		  unsigned long Vertex;
		  unsigned long Parent;
		  _TEdge Cost;
	  };
	  struct TDijkstraComparator
	  {
		  bool operator() (TDijkstraNode lhs, TDijkstraNode rhs) const
		  {
			  return lhs.Cost < rhs.Cost;//reisar const
		  }
	  };
  public:
  typedef std::pair <long, double> arista;
	typedef std::map< long, std::vector<arista> > Graf;
	typedef std::map<long, arista > ArbC;
  public:
    typedef std::vector< _TVertex > TVertices;
    typedef std::map< unsigned long, _TEdge > TRow;
    typedef std::map< unsigned long, TRow >   TMatrix;
	typedef std::vector<_TEdge> TMinimumSpanningTree;

  public:
    Grafo( );
    virtual ~Grafo( );
    void clearG( );
	   std::vector<_TEdge> Dijkstra( unsigned long & start);
     unsigned long GetNumberOfVertices( ) const;
     const _TVertex& GetVertex( unsigned long i ) const;
    long AddVertex( const _TVertex& v );
    long RemoveVertex( unsigned int i );
    long AddEdge( unsigned long a, unsigned long b, const _TEdge& cost );
	_TEdge buscarDato(const _TEdge& dato,std::vector<_TEdge>* tree);

}

	Graf g;
	Grafo();
	virtual ~ Grafo();
  void print( int destino );
¿¿ void relajacion( int actual , int adyacente , int peso );
  //inicializa el sistema
 void init();
¿  void imprimir_informe_prim();
  typedef std::pair<double,long> pair_type;
  struct Compare
  {
    bool operator()(const pair_type& a, const pair_type& b)
    {
      return a.first > b.first;
    }
  };
  private:
  std::vector<bool> visitado;

  };
  protected:
    TVertices m_Vertices;
    TMatrix   m_Edges;
  };

#endif
