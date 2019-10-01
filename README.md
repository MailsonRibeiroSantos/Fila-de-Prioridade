# Fila-de-Prioridade
O projeto possui o objetivo de implementa uma fila prioritária com uma pilha binária.
A seguir temos os seguites metodos implementados:<br/>
<ul>
<li>PQ (const Compare &cmp=Compare());</li>
<li>PQ (const std::initializer_list< ValueType > &ilist, const Compare &cmp=Compare());</li>
<li>PQ (InputIt first, InputIt last, const Compare &cmp=Compare());</li>
<li>PQ (const PQ &);</li>
<li>PQ & 	operator= (const PQ &rhs);</li>
<li>virtual 	~PQ ();</li>
const_reference 	top (void);</li>
<li>bool 	empty (void) const;</li>
<li>size_type 	size (void) const;</li>
<li>void 	clear ();</li>
<li>void 	push (const_reference x);</li>
<li>void 	pop ();</li>
<li>void 	toss (const ValueType &x);</li>
<li>void 	print () const;</li>
<li>void 	fix_heap ();</li>
<li>void 	move_down (size_type item_idx);</li>
<li>void 	move_up (size_type item_idx);</li>
<li>void 	reserve (size_type new_cap);</li>
<li>bool 	full (void) const;</li>
</ul>
 
