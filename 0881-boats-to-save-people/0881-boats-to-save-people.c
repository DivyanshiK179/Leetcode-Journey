int compare(const void* a,const void* b)
{
    return(*(int*)a-*(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
        int boat=0;
        qsort(people,peopleSize,sizeof(int),compare);
        int i=0;
        int j=peopleSize-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
            }
            j--;
            boat++;
        }
        return boat;
}