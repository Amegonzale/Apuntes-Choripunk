// [l, r] = rango donde podria estar la respuesta, incluyendo bordes

// condicion: F F F F F V V V V V

// el ultimo que es falso
int l = 0, r = n-1;
while(l != r)
{
    int mid = (l + r + 1) / 2;
    if(condicion(mid))
        r = mid-1;
    else
        l = mid;
}

// el primero que es verdadero
int l = 0, r = n-1;
while(l != r)
{
    int mid = (l + r) / 2;
    if(condicion(mid))
        r = mid;
    else
        l = mid+1;
}

// condicion: V V V V V F F F F F

// el ultimo que es verdadero
int l = 0, r = n-1;
while(l != r)
{
    int mid = (l + r + 1) / 2;
    if(condicion(mid))
        l = mid;
    else
        r = mid-1;
}

// el primero que es falso
int l = 0, r = n-1;
while(l != r)
{
    int mid = (l + r) / 2;
    if(condicion(mid))
        l = mid+1;
    else
        r = mid;
}