short mu[MAXN] = {0,1};
void mobius(){
    repx(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}
