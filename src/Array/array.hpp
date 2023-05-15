int lsearch (int arr[], int size, int key)
{
    while (size != -1)
        if (arr[size--] == key) return size + 1;
    return -1;
}

int bsearch (int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key) return mid;
        if (key < arr[mid]) return bsearch(arr, low, mid - 1, key);
        if (key > arr[mid]) return bsearch(arr, mid + 1, high, key);
    }
    return -1;
}

int ibsearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int bdel(int arr[], int size, int key)
{
    int pos = bsearch(arr, 0, size - 1, key);
    if (pos == -1)
        return size;
    
    for (int i=pos; i<size - 1; i++)
        arr[i] = arr[i + 1];

    return size - 1;
}

int ldel(int arr[], int size, int key)
{
    int pos = lsearch(arr, size - 1, key);
    if (pos == -1)
        return size;
    
    for (int i=pos; i<size - 1; i++)
        arr[i] = arr[i + 1];

    return size - 1;
}

int insert(int arr[], int size, int index, int key)
{
    if (index >= size)
        return -1;
    arr[index] = key;
    return index;
}

int inserts(int arr[], int size, int index, int key)
{
    if (index >= size)
        return -1;

    int i;
    for (i=index - 1; (i>=0 && arr[i]>key); i--)
        arr[i+1] = arr[i];

    arr[i+1] = key;

    return (index + 1);
}