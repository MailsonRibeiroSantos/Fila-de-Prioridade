#include "pq.h"
template<typename ValueType , typename Compare >
//Contutor inicializa com lista de valores 
PQ< ValueType, Compare >::PQ( const std::initializer_list< ValueType >& ilist, const Compare& cmp ):
  m_cmp(cmp)
  {
 
    m_capacity=ilist.size();
    m_data.reset(new ValueType[ilist.size()]);
    for(auto i:ilist)
    {
      push(i);
    }
  }
template<typename ValueType , typename Compare>
template<typename InputIt >
//Constutor com ponteiro para inicio e fim da lista 
PQ< ValueType, Compare >::PQ 	( 	InputIt  	first,InputIt  	last,const Compare &  	cmp ):
m_cmp(cmp)
{
	m_data.reset(new ValueType[last-first]);
    m_capacity=last-first;
    auto it =first;
    auto i(0u);
    while(it !=last)
    {
      push( it[i]);
      ++it;
    }

}
template<typename ValueType, typename Compare>
//Consturto Copia
PQ< ValueType, Compare >::PQ (const PQ< ValueType, Compare > &  rhs):
  m_cmp(rhs.m_cmp),
  m_capacity(rhs.m_capacity)
  {
  	 m_data.reset(new ValueType[rhs.size()]);
    for(size_t i=0;i<rhs.size();++i)
    {
      push(rhs.m_data[i]);
    }

  }
//Construto Operator = 
template<typename ValueType , typename Compare >
PQ< ValueType, Compare > & PQ< ValueType, Compare >::operator= 	( 	const PQ< ValueType, Compare > &  	rhs	) 	
{
  m_cmp=rhs.m_cmp;
  m_data.reset(new ValueType[rhs.size()]);
  for(size_t i=0;i<rhs.size();++i)
  {
    push(rhs.m_data[i]);
  }

}
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::push(const_reference x)
 {
   //Se fila estiver cheia dobra capacidade
    if(full())
    {
      reserve(2*m_capacity);
    }
      //adiciona no final e realiza o move up
      m_length++;
      m_data[m_length-1]=x;
      move_up(m_length-1);
    

  }

template<typename ValueType , typename Compare >
typename PQ< ValueType, Compare >::const_reference PQ< ValueType, Compare >::top(void ) 	
{
    // Se não estiver seguinte as regras deve realizar fix_heap
    if(!m_sorted)
    {
      fix_heap();
      m_sorted=true;
    }
    if(!empty())
      return m_data[0];
}
template<typename ValueType, typename Compare >
void PQ< ValueType, Compare >::toss(const ValueType &x)
{
    //Se estiver cheio dobra de tamanho 
    if(full())
    {
      reserve(2*m_capacity);
    }
     //Verifica se possui filho 
      m_data[m_length]=x;
      if((m_length-1)/2>0)
      {
	//verifica se regra não e valida e seta m_sorted para false
        if(m_cmp(m_data[m_length],m_data[(m_length-1)/2]))
        {
          m_sorted=false; 
        }   
      }
      m_length++;

 }
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::pop() 
{
    // verifica se os dados estao validos antes de realizar remocao 
    if(!m_sorted)
    {
      fix_heap();
      m_sorted=true;
    }
	//remove filho e realiza operacao move_down
      	if (empty())
                  throw std::string("Heap esta vazia");
       	else {

            m_data[0] = m_data[m_length-1];
            m_length--;
            if (m_length > 0)
                move_down(0);

            }

}
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::move_down(size_type item_idx)
{
    int leftChild, rightChild, maxIndex;
    value_type tmp; 
    //pega os dois filhos
    leftChild = (2*item_idx +1);
    rightChild = (2*item_idx +2);
     //verifica filho direito
      if (m_cmp(rightChild, m_length)) {

            if (m_cmp(leftChild, m_length))
                  return;
            else
                  maxIndex = leftChild;
     //verifica filho direito
      } else {
             //pega indice maximo ou minimo depende da heap
            if (m_cmp(m_data[rightChild],m_data[leftChild]))
                  maxIndex = rightChild;
            else
                  maxIndex = leftChild;
      }
     //realiza troca entre pai e filho e chama recursivamente
      if (m_cmp(m_data[maxIndex],m_data[item_idx])) 
      {

            tmp = m_data[maxIndex];

            m_data[maxIndex] = m_data[item_idx];

            m_data[item_idx] = tmp;

            move_down(maxIndex);

      }
  }
//Realiza operacao move_up ate o pai nao quebra a regra da heap
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::move_up(size_type item_idx)
{
    int parent;
    value_type tmp;
    if(item_idx!=0)
    {
      parent =(item_idx-1)/2;
      if(m_cmp(m_data[item_idx],m_data[parent]))
      {
          tmp=m_data[parent];
          m_data[parent]=m_data[item_idx];
          m_data[item_idx]=tmp;
          move_up(parent);
      }
    }
    
  }
//Realiza operacao fix_heap 
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::fix_heap() 	
{
    for (size_t i=m_length/2; i>0; i--)
        move_down( i);
}
//liberar memoria
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::clear()
{
	 m_length=0;
	 m_data.release();
	
} 
//Reserva mais espaço para a heap 
template<typename ValueType , typename Compare >
void PQ< ValueType, Compare >::reserve( size_type  new_cap) 	
{
	if(new_cap<m_capacity)
		return;
	value_type* temp = new value_type[new_cap];
	for(size_t i=0;i<m_capacity;++i)
		temp[i]=m_data[i];

	m_data.reset(temp);
	m_capacity= new_cap;
}	
   


