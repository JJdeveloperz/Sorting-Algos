#include<graphics.h>
#include<iostream.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
float a=0,c=0;
int tot=100;
int arr[5000];
int x_dist=0;
int b[5000];

void draw()
{

//delay();
int x_dist=0;
int j;
cleardevice();
for(j=0;j<tot;j++)
{
line(x_dist,450,x_dist,450-arr[j]/3);
x_dist+=5;
}

}
void insertionsort(int[],int);
void bubblesort(int[],int);
void mergesort(int *,int,int);
void merge(int *,int,int,int);
void selectionsort(int[],int);
void quick_sort(int[],int,int);
int partition(int[],int,int);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void numbers();

void main()
{
//initwindow(500,500);
numbers();
int gd=DETECT, gm,n=tot;
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
/*
setcolor(YELLOW);
cout<<"Bubblesort";
delay(1000);

bubblesort(arr,n);
numbers();
cleardevice();
setcolor(GREEN);
cout<<"Mergesort";
delay(1000);
mergesort(arr,0,n-1);
delay(1000);
cleardevice();
setcolor(RED);
numbers();
cout<<"Quicksort";
delay(1000);

quick_sort(arr,0,n-1);
delay(1000);
numbers();
cleardevice();
setcolor(YELLOW);
cout<<"Selectionsort";
delay(1000);

selectionsort(arr,n);
delay(1000);
numbers();
cleardevice();
setcolor(BLUE);
cout<<"Insertionsort";
delay(1000);

insertionsort(arr,n);
delay(1000);
numbers();
cleardevice();
setcolor(RED);
  */
cout<<"Heapsort";
delay(1000);

heapSort(arr,n);
delay(1000);
getch();
closegraph();
}



void bubblesort(int a[] ,int n)
{

 for(int k=0;k<n;++k)
 {
  for(int l=k+1;l<n;++l)
  {

   if(a[k] > a[l])
   {
    int temp;
    temp=arr[k];
    a[k]=a[l];
    a[l]=temp;

    draw();

   }
  }
 }

}









void mergesort(int a[],int i,int j)
{
   int mid;
   if(i<j)
   {
      mid=(i+j)/2;
      mergesort(a,i,mid);
      mergesort(a,mid+1,j);
      merge(a,i,mid,j);
   }
}
void merge(int a[],int low,int mid ,int high)
{
   int h,i,j,k;
   h=low;
   i=low;
    j=mid+1;
   while(h<=mid && j<=high)
   {
      if(a[h]<=a[j])
	 b[i]=a[h++];
      else
	 b[i]=a[j++];
      i++;
   }

   if( h > mid)
      for(k=j;k<=high;k++)
	b[i++]=a[k];
   else
      for(k=h;k<=mid;k++)
	 b[i++]=a[k];


   for(k=low;k<=high;k++)
   {  a[k]=b[k];

   draw();
   }

}


void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
	j=partition(a,l,u);
	quick_sort(a,l,j-1);
	quick_sort(a,j+1,u);


    }
}


int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
	do
	    i++;

	while(a[i]<v&&i<=u);

	do
	    j--;
	while(v<a[j]);

	if(i<j)
	{
	    temp=a[i];
	    a[i]=a[j];
	    a[j]=temp;
	}
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

     draw();
    return(j);
}




void selectionsort(int a[],int n)
{     int i,loc,j,min,temp;
for(i=0;i<n;i++)
    {
	min=a[i];
	loc=i;
	for(j=i+1;j<n;j++)
	{
	    if(min>a[j])
	    {
		min=a[j];
		loc=j;
	    }
	}

	temp=a[i];
	a[i]=a[loc];
	a[loc]=temp;

draw();
    }
 }




void insertionsort(int a[],int n)
{
int temp,i,j;
 for(i=1;i<=n-1;i++)
    {
	temp=a[i];
	j=i-1;

	while((temp<arr[j])&&(j>=0))
	{
	    a[j+1]=a[j];    //moves element forward
	    j=j-1;
	}

	a[j+1]=temp;    //insert element in proper place

draw();

    }
}




void heapify(int arr[], int n, int i) {
   int temp;
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && arr[l] > arr[largest])
      largest = l;
   if (r < n && arr[r] > arr[largest])
      largest = r;
   if (largest != i) {
      temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}
void heapSort(int arr[], int n) {
   int temp;
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

   for (int j = n - 1; j >= 0; j--) {
      temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      heapify(arr, j, 0);

draw();

   }
}


 void numbers()
 {
arr[ 0 ]= 280 ;
arr[ 1 ]= 373 ;
arr[ 2 ]= 489 ;
arr[ 3 ]= 960 ;
arr[ 4 ]= 200 ;
arr[ 5 ]= 893 ;
arr[ 6 ]= 462 ;
arr[ 7 ]= 631 ;
arr[ 8 ]= 685 ;
arr[ 9 ]= 654 ;
arr[ 10 ]= 857 ;
arr[ 11 ]= 425 ;
arr[ 12 ]= 54 ;
arr[ 13 ]= 699 ;
arr[ 14 ]= 868 ;
arr[ 15 ]= 378 ;
arr[ 16 ]= 365 ;
arr[ 17 ]= 204 ;
arr[ 18 ]= 804 ;
arr[ 19 ]= 637 ;
arr[ 20 ]= 502 ;
arr[ 21 ]= 936 ;
arr[ 22 ]= 318 ;
arr[ 23 ]= 717 ;
arr[ 24 ]= 367 ;
arr[ 25 ]= 395 ;
arr[ 26 ]= 468 ;
arr[ 27 ]= 234 ;
arr[ 28 ]= 814 ;
arr[ 29 ]= 575 ;
arr[ 30 ]= 197 ;
arr[ 31 ]= 478 ;
arr[ 32 ]= 251 ;
arr[ 33 ]= 940 ;
arr[ 34 ]= 844 ;
arr[ 35 ]= 64 ;
arr[ 36 ]= 667 ;
arr[ 37 ]= 811 ;
arr[ 38 ]= 521 ;
arr[ 39 ]= 95 ;
arr[ 40 ]= 915 ;
arr[ 41 ]= 856 ;
arr[ 42 ]= 896 ;
arr[ 43 ]= 154 ;
arr[ 44 ]= 906 ;
arr[ 45 ]= 609 ;
arr[ 46 ]= 620 ;
arr[ 47 ]= 162 ;
arr[ 48 ]= 711 ;
arr[ 49 ]= 991 ;
arr[ 50 ]= 742 ;
arr[ 51 ]= 651 ;
arr[ 52 ]= 309 ;
arr[ 53 ]= 955 ;
arr[ 54 ]= 633 ;
arr[ 55 ]= 267 ;
arr[ 56 ]= 680 ;
arr[ 57 ]= 257 ;
arr[ 58 ]= 177 ;
arr[ 59 ]= 7 ;
arr[ 60 ]= 199 ;
arr[ 61 ]= 822 ;
arr[ 62 ]= 950 ;
arr[ 63 ]= 131 ;
arr[ 64 ]= 736 ;
arr[ 65 ]= 772 ;
arr[ 66 ]= 149 ;
arr[ 67 ]= 626 ;
arr[ 68 ]= 325 ;
arr[ 69 ]= 402 ;
arr[ 70 ]= 727 ;
arr[ 71 ]= 917 ;
arr[ 72 ]= 75 ;
arr[ 73 ]= 262 ;
arr[ 74 ]= 927 ;
arr[ 75 ]= 647 ;
arr[ 76 ]= 806 ;
arr[ 77 ]= 305 ;
arr[ 78 ]= 386 ;
arr[ 79 ]= 867 ;
arr[ 80 ]= 894 ;
arr[ 81 ]= 85 ;
arr[ 82 ]= 460 ;
arr[ 83 ]= 161 ;
arr[ 84 ]= 264 ;
arr[ 85 ]= 323 ;
arr[ 86 ]= 617 ;
arr[ 87 ]= 760 ;
arr[ 88 ]= 708 ;
arr[ 89 ]= 26 ;
arr[ 90 ]= 746 ;
arr[ 91 ]= 416 ;
arr[ 92 ]= 570 ;
arr[ 93 ]= 144 ;
arr[ 94 ]= 630 ;
arr[ 95 ]= 539 ;
arr[ 96 ]= 830 ;
arr[ 97 ]= 320 ;
arr[ 98 ]= 842 ;
arr[ 99 ]= 327 ;
arr[ 100 ]= 265 ;
arr[ 101 ]= 723 ;
arr[ 102 ]= 342 ;
arr[ 103 ]= 983 ;
arr[ 104 ]= 897 ;
arr[ 105 ]= 195 ;
arr[ 106 ]= 829 ;
arr[ 107 ]= 698 ;
arr[ 108 ]= 792 ;
arr[ 109 ]= 60 ;
arr[ 110 ]= 453 ;
arr[ 111 ]= 210 ;
arr[ 112 ]= 536 ;
arr[ 113 ]= 296 ;
arr[ 114 ]= 527 ;
arr[ 115 ]= 252 ;
arr[ 116 ]= 520 ;
arr[ 117 ]= 984 ;
arr[ 118 ]= 535 ;
arr[ 119 ]= 741 ;
arr[ 120 ]= 934 ;
arr[ 121 ]= 38 ;
arr[ 122 ]= 775 ;
arr[ 123 ]= 786 ;
arr[ 124 ]= 816 ;
arr[ 125 ]= 597 ;
arr[ 126 ]= 457 ;
arr[ 127 ]= 61 ;
arr[ 128 ]= 355 ;
arr[ 129 ]= 671 ;
arr[ 130 ]= 514 ;
arr[ 131 ]= 459 ;
arr[ 132 ]= 564 ;
arr[ 133 ]= 585 ;
arr[ 134 ]= 415 ;
arr[ 135 ]= 270 ;
arr[ 136 ]= 861 ;
arr[ 137 ]= 595 ;
arr[ 138 ]= 995 ;
arr[ 139 ]= 859 ;
arr[ 140 ]= 632 ;
arr[ 141 ]= 689 ;
arr[ 142 ]= 881 ;
arr[ 143 ]= 260 ;
arr[ 144 ]= 837 ;
arr[ 145 ]= 436 ;
arr[ 146 ]= 114 ;
arr[ 147 ]= 779 ;
arr[ 148 ]= 387 ;
arr[ 149 ]= 148 ;
arr[ 150 ]= 985 ;
arr[ 151 ]= 763 ;
arr[ 152 ]= 190 ;
arr[ 153 ]= 782 ;
arr[ 154 ]= 799 ;
arr[ 155 ]= 30 ;
arr[ 156 ]= 879 ;
arr[ 157 ]= 734 ;
arr[ 158 ]= 15 ;
arr[ 159 ]= 481 ;
arr[ 160 ]= 695 ;
arr[ 161 ]= 758 ;
arr[ 162 ]= 2 ;
arr[ 163 ]= 188 ;
arr[ 164 ]= 501 ;
arr[ 165 ]= 577 ;
arr[ 166 ]= 642 ;
arr[ 167 ]= 725 ;
arr[ 168 ]= 525 ;
arr[ 169 ]= 407 ;
arr[ 170 ]= 268 ;
arr[ 171 ]= 601 ;
arr[ 172 ]= 660 ;
arr[ 173 ]= 888 ;
arr[ 174 ]= 518 ;
arr[ 175 ]= 28 ;
arr[ 176 ]= 548 ;
arr[ 177 ]= 928 ;
arr[ 178 ]= 683 ;
arr[ 179 ]= 143 ;
arr[ 180 ]= 622 ;
arr[ 181 ]= 335 ;
arr[ 182 ]= 314 ;
arr[ 183 ]= 450 ;
arr[ 184 ]= 770 ;
arr[ 185 ]= 629 ;
arr[ 186 ]= 877 ;
arr[ 187 ]= 220 ;
arr[ 188 ]= 993 ;
arr[ 189 ]= 771 ;
arr[ 190 ]= 669 ;
arr[ 191 ]= 126 ;
arr[ 192 ]= 687 ;
arr[ 193 ]= 240 ;
arr[ 194 ]= 846 ;
arr[ 195 ]= 118 ;
arr[ 196 ]= 259 ;
arr[ 197 ]= 785 ;
arr[ 198 ]= 229 ;
arr[ 199 ]= 709 ;
arr[ 200 ]= 878 ;
arr[ 201 ]= 599 ;
arr[ 202 ]= 84 ;
arr[ 203 ]= 643 ;
arr[ 204 ]= 988 ;
arr[ 205 ]= 805 ;
arr[ 206 ]= 621 ;
arr[ 207 ]= 913 ;
arr[ 208 ]= 432 ;
arr[ 209 ]= 198 ;
arr[ 210 ]= 9 ;
arr[ 211 ]= 872 ;
arr[ 212 ]= 398 ;
arr[ 213 ]= 561 ;
arr[ 214 ]= 384 ;
arr[ 215 ]= 674 ;
arr[ 216 ]= 35 ;
arr[ 217 ]= 247 ;
arr[ 218 ]= 545 ;
arr[ 219 ]= 497 ;
arr[ 220 ]= 385 ;
arr[ 221 ]= 141 ;
arr[ 222 ]= 151 ;
arr[ 223 ]= 926 ;
arr[ 224 ]= 4 ;
arr[ 225 ]= 947 ;
arr[ 226 ]= 375 ;
arr[ 227 ]= 115 ;
arr[ 228 ]= 322 ;
arr[ 229 ]= 635 ;
arr[ 230 ]= 413 ;
arr[ 231 ]= 834 ;
arr[ 232 ]= 795 ;
arr[ 233 ]= 507 ;
arr[ 234 ]= 290 ;
arr[ 235 ]= 89 ;
arr[ 236 ]= 803 ;
arr[ 237 ]= 836 ;
arr[ 238 ]= 362 ;
arr[ 239 ]= 230 ;
arr[ 240 ]= 82 ;
arr[ 241 ]= 456 ;
arr[ 242 ]= 932 ;
arr[ 243 ]= 777 ;
arr[ 244 ]= 722 ;
arr[ 245 ]= 13 ;
arr[ 246 ]= 170 ;
arr[ 247 ]= 847 ;
arr[ 248 ]= 66 ;
arr[ 249 ]= 466 ;
arr[ 250 ]= 757 ;
arr[ 251 ]= 345 ;
arr[ 252 ]= 380 ;
arr[ 253 ]= 845 ;
arr[ 254 ]= 568 ;
arr[ 255 ]= 905 ;
arr[ 256 ]= 956 ;
arr[ 257 ]= 393 ;
arr[ 258 ]= 288 ;
arr[ 259 ]= 164 ;
arr[ 260 ]= 470 ;
arr[ 261 ]= 491 ;
arr[ 262 ]= 389 ;
arr[ 263 ]= 860 ;
arr[ 264 ]= 426 ;
arr[ 265 ]= 904 ;
arr[ 266 ]= 243 ;
arr[ 267 ]= 978 ;
arr[ 268 ]= 826 ;
arr[ 269 ]= 232 ;
arr[ 270 ]= 579 ;
arr[ 271 ]= 529 ;
arr[ 272 ]= 287 ;
arr[ 273 ]= 146 ;
arr[ 274 ]= 972 ;
arr[ 275 ]= 128 ;
arr[ 276 ]= 992 ;
arr[ 277 ]= 986 ;
arr[ 278 ]= 653 ;
arr[ 279 ]= 371 ;
arr[ 280 ]= 974 ;
arr[ 281 ]= 235 ;
arr[ 282 ]= 589 ;
arr[ 283 ]= 244 ;
arr[ 284 ]= 540 ;
arr[ 285 ]= 129 ;
arr[ 286 ]= 245 ;
arr[ 287 ]= 638 ;
arr[ 288 ]= 155 ;
arr[ 289 ]= 823 ;
arr[ 290 ]= 981 ;
arr[ 291 ]= 679 ;
arr[ 292 ]= 433 ;
arr[ 293 ]= 343 ;
arr[ 294 ]= 68 ;
arr[ 295 ]= 509 ;
arr[ 296 ]= 306 ;
arr[ 297 ]= 900 ;
arr[ 298 ]= 737 ;
arr[ 299 ]= 295 ;
arr[ 300 ]= 58 ;
arr[ 301 ]= 301 ;
arr[ 302 ]= 969 ;
arr[ 303 ]= 181 ;
arr[ 304 ]= 417 ;
arr[ 305 ]= 668 ;
arr[ 306 ]= 659 ;
arr[ 307 ]= 236 ;
arr[ 308 ]= 473 ;
arr[ 309 ]= 821 ;
arr[ 310 ]= 238 ;
arr[ 311 ]= 769 ;
arr[ 312 ]= 32 ;
arr[ 313 ]= 979 ;
arr[ 314 ]= 493 ;
arr[ 315 ]= 610 ;
arr[ 316 ]= 676 ;
arr[ 317 ]= 374 ;
arr[ 318 ]= 324 ;
arr[ 319 ]= 215 ;
arr[ 320 ]= 341 ;
arr[ 321 ]= 784 ;
arr[ 322 ]= 91 ;
arr[ 323 ]= 216 ;
arr[ 324 ]= 471 ;
arr[ 325 ]= 876 ;
arr[ 326 ]= 279 ;
arr[ 327 ]= 448 ;
arr[ 328 ]= 537 ;
arr[ 329 ]= 833 ;
arr[ 330 ]= 310 ;
arr[ 331 ]= 418 ;
arr[ 332 ]= 274 ;
arr[ 333 ]= 106 ;
arr[ 334 ]= 851 ;
arr[ 335 ]= 167 ;
arr[ 336 ]= 534 ;
arr[ 337 ]= 781 ;
arr[ 338 ]= 780 ;
arr[ 339 ]= 815 ;
arr[ 340 ]= 120 ;
arr[ 341 ]= 80 ;
arr[ 342 ]= 381 ;
arr[ 343 ]= 996 ;
arr[ 344 ]= 787 ;
arr[ 345 ]= 982 ;
arr[ 346 ]= 253 ;
arr[ 347 ]= 547 ;
arr[ 348 ]= 914 ;
arr[ 349 ]= 887 ;
arr[ 350 ]= 724 ;
arr[ 351 ]= 693 ;
arr[ 352 ]= 899 ;
arr[ 353 ]= 866 ;
arr[ 354 ]= 332 ;
arr[ 355 ]= 266 ;
arr[ 356 ]= 142 ;
arr[ 357 ]= 552 ;
arr[ 358 ]= 179 ;
arr[ 359 ]= 922 ;
arr[ 360 ]= 442 ;
arr[ 361 ]= 790 ;
arr[ 362 ]= 383 ;
arr[ 363 ]= 316 ;
arr[ 364 ]= 873 ;
arr[ 365 ]= 649 ;
arr[ 366 ]= 556 ;
arr[ 367 ]= 848 ;
arr[ 368 ]= 546 ;
arr[ 369 ]= 608 ;
arr[ 370 ]= 24 ;
arr[ 371 ]= 766 ;
arr[ 372 ]= 422 ;
arr[ 373 ]= 396 ;
arr[ 374 ]= 615 ;
arr[ 375 ]= 311 ;
arr[ 376 ]= 571 ;
arr[ 377 ]= 173 ;
arr[ 378 ]= 427 ;
arr[ 379 ]= 889 ;
arr[ 380 ]= 485 ;
arr[ 381 ]= 283 ;
arr[ 382 ]= 828 ;
arr[ 383 ]= 447 ;
arr[ 384 ]= 942 ;
arr[ 385 ]= 52 ;
arr[ 386 ]= 591 ;
arr[ 387 ]= 344 ;
arr[ 388 ]= 438 ;
arr[ 389 ]= 726 ;
arr[ 390 ]= 359 ;
arr[ 391 ]= 551 ;
arr[ 392 ]= 86 ;
arr[ 393 ]= 194 ;
arr[ 394 ]= 211 ;
arr[ 395 ]= 512 ;
arr[ 396 ]= 12 ;
arr[ 397 ]= 182 ;
arr[ 398 ]= 533 ;
arr[ 399 ]= 543 ;
arr[ 400 ]= 366 ;
arr[ 401 ]= 511 ;
arr[ 402 ]= 175 ;
arr[ 403 ]= 340 ;
arr[ 404 ]= 254 ;
arr[ 405 ]= 298 ;
arr[ 406 ]= 663 ;
arr[ 407 ]= 884 ;
arr[ 408 ]= 411 ;
arr[ 409 ]= 840 ;
arr[ 410 ]= 661 ;
arr[ 411 ]= 958 ;
arr[ 412 ]= 112 ;
arr[ 413 ]= 912 ;
arr[ 414 ]= 827 ;
arr[ 415 ]= 696 ;
arr[ 416 ]= 584 ;
arr[ 417 ]= 420 ;
arr[ 418 ]= 788 ;
arr[ 419 ]= 764 ;
arr[ 420 ]= 93 ;
arr[ 421 ]= 176 ;
arr[ 422 ]= 474 ;
arr[ 423 ]= 326 ;
arr[ 424 ]= 104 ;
arr[ 425 ]= 704 ;
arr[ 426 ]= 187 ;
arr[ 427 ]= 980 ;
arr[ 428 ]= 892 ;
arr[ 429 ]= 871 ;
arr[ 430 ]= 931 ;
arr[ 431 ]= 477 ;
arr[ 432 ]= 745 ;
arr[ 433 ]= 819 ;
arr[ 434 ]= 765 ;
arr[ 435 ]= 189 ;
arr[ 436 ]= 116 ;
arr[ 437 ]= 70 ;
arr[ 438 ]= 977 ;
arr[ 439 ]= 530 ;
arr[ 440 ]= 813 ;
arr[ 441 ]= 998 ;
arr[ 442 ]= 382 ;
arr[ 443 ]= 171 ;
arr[ 444 ]= 51 ;
arr[ 445 ]= 124 ;
arr[ 446 ]= 494 ;
arr[ 447 ]= 678 ;
arr[ 448 ]= 692 ;
arr[ 449 ]= 526 ;
arr[ 450 ]= 700 ;
arr[ 451 ]= 853 ;
arr[ 452 ]= 429 ;
arr[ 453 ]= 895 ;
arr[ 454 ]= 987 ;
arr[ 455 ]= 791 ;
arr[ 456 ]= 428 ;
arr[ 457 ]= 369 ;
arr[ 458 ]= 516 ;
arr[ 459 ]= 596 ;
arr[ 460 ]= 44 ;
arr[ 461 ]= 358 ;
arr[ 462 ]= 962 ;
arr[ 463 ]= 315 ;
arr[ 464 ]= 735 ;
arr[ 465 ]= 163 ;
arr[ 466 ]= 414 ;
arr[ 467 ]= 157 ;
arr[ 468 ]= 174 ;
arr[ 469 ]= 11 ;
arr[ 470 ]= 870 ;
arr[ 471 ]= 839 ;
arr[ 472 ]= 524 ;
arr[ 473 ]= 612 ;
arr[ 474 ]= 794 ;
arr[ 475 ]= 353 ;
arr[ 476 ]= 858 ;
arr[ 477 ]= 329 ;
arr[ 478 ]= 945 ;
arr[ 479 ]= 69 ;
arr[ 480 ]= 331 ;
arr[ 481 ]= 759 ;
arr[ 482 ]= 379 ;
arr[ 483 ]= 504 ;
arr[ 484 ]= 130 ;
arr[ 485 ]= 368 ;
arr[ 486 ]= 201 ;
arr[ 487 ]= 673 ;
arr[ 488 ]= 334 ;
arr[ 489 ]= 205 ;
arr[ 490 ]= 946 ;
arr[ 491 ]= 747 ;
arr[ 492 ]= 226 ;
arr[ 493 ]= 449 ;
arr[ 494 ]= 372 ;
arr[ 495 ]= 53 ;
arr[ 496 ]= 452 ;
arr[ 497 ]= 113 ;
arr[ 498 ]= 476 ;
arr[ 499 ]= 658 ;
arr[ 500 ]= 222 ;
arr[ 501 ]= 281 ;
arr[ 502 ]= 939 ;
arr[ 503 ]= 363 ;
arr[ 504 ]= 541 ;
arr[ 505 ]= 423 ;
arr[ 506 ]= 648 ;
arr[ 507 ]= 437 ;
arr[ 508 ]= 909 ;
arr[ 509 ]= 153 ;
arr[ 510 ]= 605 ;
arr[ 511 ]= 258 ;
arr[ 512 ]= 356 ;
arr[ 513 ]= 916 ;
arr[ 514 ]= 650 ;
arr[ 515 ]= 968 ;
arr[ 516 ]= 855 ;
arr[ 517 ]= 943 ;
arr[ 518 ]= 475 ;
arr[ 519 ]= 590 ;
arr[ 520 ]= 644 ;
arr[ 521 ]= 242 ;
arr[ 522 ]= 572 ;
arr[ 523 ]= 50 ;
arr[ 524 ]= 434 ;
arr[ 525 ]= 294 ;
arr[ 526 ]= 762 ;
arr[ 527 ]= 119 ;
arr[ 528 ]= 292 ;
arr[ 529 ]= 593 ;
arr[ 530 ]= 600 ;
arr[ 531 ]= 875 ;
arr[ 532 ]= 898 ;
arr[ 533 ]= 973 ;
arr[ 534 ]= 62 ;
arr[ 535 ]= 639 ;
arr[ 536 ]= 390 ;
arr[ 537 ]= 616 ;
arr[ 538 ]= 567 ;
arr[ 539 ]= 214 ;
arr[ 540 ]= 435 ;
arr[ 541 ]= 377 ;
arr[ 542 ]= 152 ;
arr[ 543 ]= 944 ;
arr[ 544 ]= 446 ;
arr[ 545 ]= 41 ;
arr[ 546 ]= 193 ;
arr[ 547 ]= 852 ;
arr[ 548 ]= 14 ;
arr[ 549 ]= 869 ;
arr[ 550 ]= 159 ;
arr[ 551 ]= 286 ;
arr[ 552 ]= 656 ;
arr[ 553 ]= 76 ;
arr[ 554 ]= 397 ;
arr[ 555 ]= 134 ;
arr[ 556 ]= 783 ;
arr[ 557 ]= 812 ;
arr[ 558 ]= 97 ;
arr[ 559 ]= 330 ;
arr[ 560 ]= 733 ;
arr[ 561 ]= 203 ;
arr[ 562 ]= 137 ;
arr[ 563 ]= 624 ;
arr[ 564 ]= 430 ;
arr[ 565 ]= 697 ;
arr[ 566 ]= 701 ;
arr[ 567 ]= 586 ;
arr[ 568 ]= 850 ;
arr[ 569 ]= 6 ;
arr[ 570 ]= 716 ;
arr[ 571 ]= 138 ;
arr[ 572 ]= 275 ;
arr[ 573 ]= 550 ;
arr[ 574 ]= 34 ;
arr[ 575 ]= 136 ;
arr[ 576 ]= 835 ;
arr[ 577 ]= 319 ;
arr[ 578 ]= 291 ;
arr[ 579 ]= 824 ;
arr[ 580 ]= 47 ;
arr[ 581 ]= 508 ;
arr[ 582 ]= 101 ;
arr[ 583 ]= 404 ;
arr[ 584 ]= 256 ;
arr[ 585 ]= 714 ;
arr[ 586 ]= 223 ;
arr[ 587 ]= 499 ;
arr[ 588 ]= 224 ;
arr[ 589 ]= 604 ;
arr[ 590 ]= 77 ;
arr[ 591 ]= 308 ;
arr[ 592 ]= 202 ;
arr[ 593 ]= 776 ;
arr[ 594 ]= 180 ;
arr[ 595 ]= 908 ;
arr[ 596 ]= 110 ;
arr[ 597 ]= 657 ;
arr[ 598 ]= 206 ;
arr[ 599 ]= 107 ;
arr[ 600 ]= 350 ;
arr[ 601 ]= 364 ;
arr[ 602 ]= 92 ;
arr[ 603 ]= 682 ;
arr[ 604 ]= 83 ;
arr[ 605 ]= 713 ;
arr[ 606 ]= 400 ;
arr[ 607 ]= 147 ;
arr[ 608 ]= 750 ;
arr[ 609 ]= 730 ;
arr[ 610 ]= 554 ;
arr[ 611 ]= 158 ;
arr[ 612 ]= 911 ;
arr[ 613 ]= 670 ;
arr[ 614 ]= 749 ;
arr[ 615 ]= 127 ;
arr[ 616 ]= 480 ;
arr[ 617 ]= 739 ;
arr[ 618 ]= 346 ;
arr[ 619 ]= 443 ;
arr[ 620 ]= 463 ;
arr[ 621 ]= 728 ;
arr[ 622 ]= 938 ;
arr[ 623 ]= 483 ;
arr[ 624 ]= 710 ;
arr[ 625 ]= 519 ;
arr[ 626 ]= 90 ;
arr[ 627 ]= 18 ;
arr[ 628 ]= 999 ;
arr[ 629 ]= 618 ;
arr[ 630 ]= 623 ;
arr[ 631 ]= 729 ;
arr[ 632 ]= 307 ;
arr[ 633 ]= 720 ;
arr[ 634 ]= 664 ;
arr[ 635 ]= 490 ;
arr[ 636 ]= 686 ;
arr[ 637 ]= 744 ;
arr[ 638 ]= 440 ;
arr[ 639 ]= 809 ;
arr[ 640 ]= 751 ;
arr[ 641 ]= 665 ;
arr[ 642 ]= 966 ;
arr[ 643 ]= 505 ;
arr[ 644 ]= 930 ;
arr[ 645 ]= 8 ;
arr[ 646 ]= 563 ;
arr[ 647 ]= 492 ;
arr[ 648 ]= 421 ;
arr[ 649 ]= 902 ;
arr[ 650 ]= 553 ;
arr[ 651 ]= 531 ;
arr[ 652 ]= 65 ;
arr[ 653 ]= 132 ;
arr[ 654 ]= 820 ;
arr[ 655 ]= 574 ;
arr[ 656 ]= 284 ;
arr[ 657 ]= 566 ;
arr[ 658 ]= 628 ;
arr[ 659 ]= 338 ;
arr[ 660 ]= 465 ;
arr[ 661 ]= 111 ;
arr[ 662 ]= 271 ;
arr[ 663 ]= 587 ;
arr[ 664 ]= 300 ;
arr[ 665 ]= 391 ;
arr[ 666 ]= 789 ;
arr[ 667 ]= 249 ;
arr[ 668 ]= 183 ;
arr[ 669 ]= 838 ;
arr[ 670 ]= 961 ;
arr[ 671 ]= 336 ;
arr[ 672 ]= 419 ;
arr[ 673 ]= 691 ;
arr[ 674 ]= 957 ;
arr[ 675 ]= 580 ;
arr[ 676 ]= 406 ;
arr[ 677 ]= 582 ;
arr[ 678 ]= 949 ;
arr[ 679 ]= 681 ;
arr[ 680 ]= 964 ;
arr[ 681 ]= 139 ;
arr[ 682 ]= 184 ;
arr[ 683 ]= 886 ;
arr[ 684 ]= 560 ;
arr[ 685 ]= 971 ;
arr[ 686 ]= 467 ;
arr[ 687 ]= 808 ;
arr[ 688 ]= 565 ;
arr[ 689 ]= 941 ;
arr[ 690 ]= 800 ;
arr[ 691 ]= 625 ;
arr[ 692 ]= 42 ;
arr[ 693 ]= 339 ;
arr[ 694 ]= 208 ;
arr[ 695 ]= 273 ;
arr[ 696 ]= 255 ;
arr[ 697 ]= 818 ;
arr[ 698 ]= 907 ;
arr[ 699 ]= 592 ;
arr[ 700 ]= 532 ;
arr[ 701 ]= 444 ;
arr[ 702 ]= 269 ;
arr[ 703 ]= 172 ;
arr[ 704 ]= 719 ;
arr[ 705 ]= 778 ;
arr[ 706 ]= 672 ;
arr[ 707 ]= 357 ;
arr[ 708 ]= 970 ;
arr[ 709 ]= 185 ;
arr[ 710 ]= 79 ;
arr[ 711 ]= 63 ;
arr[ 712 ]= 160 ;
arr[ 713 ]= 707 ;
arr[ 714 ]= 277 ;
arr[ 715 ]= 721 ;
arr[ 716 ]= 832 ;
arr[ 717 ]= 797 ;
arr[ 718 ]= 712 ;
arr[ 719 ]= 874 ;
arr[ 720 ]= 57 ;
arr[ 721 ]= 807 ;
arr[ 722 ]= 109 ;
arr[ 723 ]= 303 ;
arr[ 724 ]= 67 ;
arr[ 725 ]= 925 ;
arr[ 726 ]= 862 ;
arr[ 727 ]= 98 ;
arr[ 728 ]= 29 ;
arr[ 729 ]= 544 ;
arr[ 730 ]= 666 ;
arr[ 731 ]= 263 ;
arr[ 732 ]= 538 ;
arr[ 733 ]= 16 ;
arr[ 734 ]= 740 ;
arr[ 735 ]= 312 ;
arr[ 736 ]= 394 ;
arr[ 737 ]= 156 ;
arr[ 738 ]= 718 ;
arr[ 739 ]= 333 ;
arr[ 740 ]= 796 ;
arr[ 741 ]= 361 ;
arr[ 742 ]= 351 ;
arr[ 743 ]= 228 ;
arr[ 744 ]= 22 ;
arr[ 745 ]= 73 ;
arr[ 746 ]= 458 ;
arr[ 747 ]= 23 ;
arr[ 748 ]= 166 ;
arr[ 749 ]= 25 ;
arr[ 750 ]= 88 ;
arr[ 751 ]= 515 ;
arr[ 752 ]= 910 ;
arr[ 753 ]= 94 ;
arr[ 754 ]= 513 ;
arr[ 755 ]= 954 ;
arr[ 756 ]= 989 ;
arr[ 757 ]= 10 ;
arr[ 758 ]= 645 ;
arr[ 759 ]= 285 ;
arr[ 760 ]= 903 ;
arr[ 761 ]= 731 ;
arr[ 762 ]= 196 ;
arr[ 763 ]= 121 ;
arr[ 764 ]= 920 ;
arr[ 765 ]= 178 ;
arr[ 766 ]= 976 ;
arr[ 767 ]= 168 ;
arr[ 768 ]= 37 ;
arr[ 769 ]= 662 ;
arr[ 770 ]= 304 ;
arr[ 771 ]= 100 ;
arr[ 772 ]= 451 ;
arr[ 773 ]= 39 ;
arr[ 774 ]= 801 ;
arr[ 775 ]= 409 ;
arr[ 776 ]= 921 ;
arr[ 777 ]= 603 ;
arr[ 778 ]= 496 ;
arr[ 779 ]= 36 ;
arr[ 780 ]= 994 ;
arr[ 781 ]= 817 ;
arr[ 782 ]= 549 ;
arr[ 783 ]= 588 ;
arr[ 784 ]= 694 ;
arr[ 785 ]= 71 ;
arr[ 786 ]= 464 ;
arr[ 787 ]= 935 ;
arr[ 788 ]= 87 ;
arr[ 789 ]= 472 ;
arr[ 790 ]= 78 ;
arr[ 791 ]= 688 ;
arr[ 792 ]= 145 ;
arr[ 793 ]= 337 ;
arr[ 794 ]= 360 ;
arr[ 795 ]= 1 ;
arr[ 796 ]= 498 ;
arr[ 797 ]= 646 ;
arr[ 798 ]= 990 ;
arr[ 799 ]= 706 ;
arr[ 800 ]= 517 ;
arr[ 801 ]= 221 ;
arr[ 802 ]= 233 ;
arr[ 803 ]= 454 ;
arr[ 804 ]= 96 ;
arr[ 805 ]= 231 ;
arr[ 806 ]= 702 ;
arr[ 807 ]= 975 ;
arr[ 808 ]= 743 ;
arr[ 809 ]= 239 ;
arr[ 810 ]= 225 ;
arr[ 811 ]= 403 ;
arr[ 812 ]= 135 ;
arr[ 813 ]= 272 ;
arr[ 814 ]= 276 ;
arr[ 815 ]= 401 ;
arr[ 816 ]= 864 ;
arr[ 817 ]= 3 ;
arr[ 818 ]= 219 ;
arr[ 819 ]= 248 ;
arr[ 820 ]= 705 ;
arr[ 821 ]= 606 ;
arr[ 822 ]= 802 ;
arr[ 823 ]= 261 ;
arr[ 824 ]= 461 ;
arr[ 825 ]= 43 ;
arr[ 826 ]= 297 ;
arr[ 827 ]= 768 ;
arr[ 828 ]= 59 ;
arr[ 829 ]= 282 ;
arr[ 830 ]= 619 ;
arr[ 831 ]= 885 ;
arr[ 832 ]= 486 ;
arr[ 833 ]= 20 ;
arr[ 834 ]= 441 ;
arr[ 835 ]= 469 ;
arr[ 836 ]= 482 ;
arr[ 837 ]= 863 ;
arr[ 838 ]= 455 ;
arr[ 839 ]= 843 ;
arr[ 840 ]= 611 ;
arr[ 841 ]= 117 ;
arr[ 842 ]= 578 ;
arr[ 843 ]= 583 ;
arr[ 844 ]= 773 ;
arr[ 845 ]= 756 ;
arr[ 846 ]= 105 ;
arr[ 847 ]= 348 ;
arr[ 848 ]= 752 ;
arr[ 849 ]= 627 ;
arr[ 850 ]= 798 ;
arr[ 851 ]= 227 ;
arr[ 852 ]= 891 ;
arr[ 853 ]= 370 ;
arr[ 854 ]= 690 ;
arr[ 855 ]= 677 ;
arr[ 856 ]= 74 ;
arr[ 857 ]= 192 ;
arr[ 858 ]= 522 ;
arr[ 859 ]= 5 ;
arr[ 860 ]= 99 ;
arr[ 861 ]= 959 ;
arr[ 862 ]= 133 ;
arr[ 863 ]= 349 ;
arr[ 864 ]= 503 ;
arr[ 865 ]= 952 ;
arr[ 866 ]= 929 ;
arr[ 867 ]= 289 ;
arr[ 868 ]= 299 ;
arr[ 869 ]= 831 ;
arr[ 870 ]= 72 ;
arr[ 871 ]= 250 ;
arr[ 872 ]= 317 ;
arr[ 873 ]= 33 ;
arr[ 874 ]= 399 ;
arr[ 875 ]= 27 ;
arr[ 876 ]= 919 ;
arr[ 877 ]= 562 ;
arr[ 878 ]= 555 ;
arr[ 879 ]= 506 ;
arr[ 880 ]= 140 ;
arr[ 881 ]= 755 ;
arr[ 882 ]= 500 ;
arr[ 883 ]= 19 ;
arr[ 884 ]= 854 ;
arr[ 885 ]= 408 ;
arr[ 886 ]= 376 ;
arr[ 887 ]= 810 ;
arr[ 888 ]= 217 ;
arr[ 889 ]= 213 ;
arr[ 890 ]= 207 ;
arr[ 891 ]= 684 ;
arr[ 892 ]= 634 ;
arr[ 893 ]= 918 ;
arr[ 894 ]= 967 ;
arr[ 895 ]= 46 ;
arr[ 896 ]= 542 ;
arr[ 897 ]= 753 ;
arr[ 898 ]= 209 ;
arr[ 899 ]= 965 ;
arr[ 900 ]= 186 ;
arr[ 901 ]= 40 ;
arr[ 902 ]= 412 ;
arr[ 903 ]= 882 ;
arr[ 904 ]= 754 ;
arr[ 905 ]= 21 ;
arr[ 906 ]= 557 ;
arr[ 907 ]= 715 ;
arr[ 908 ]= 108 ;
arr[ 909 ]= 424 ;
arr[ 910 ]= 655 ;
arr[ 911 ]= 937 ;
arr[ 912 ]= 558 ;
arr[ 913 ]= 652 ;
arr[ 914 ]= 703 ;
arr[ 915 ]= 278 ;
arr[ 916 ]= 313 ;
arr[ 917 ]= 237 ;
arr[ 918 ]= 212 ;
arr[ 919 ]= 328 ;
arr[ 920 ]= 510 ;
arr[ 921 ]= 748 ;
arr[ 922 ]= 123 ;
arr[ 923 ]= 122 ;
arr[ 924 ]= 528 ;
arr[ 925 ]= 102 ;
arr[ 926 ]= 675 ;
arr[ 927 ]= 883 ;
arr[ 928 ]= 352 ;
arr[ 929 ]= 923 ;
arr[ 930 ]= 293 ;
arr[ 931 ]= 165 ;
arr[ 932 ]= 997 ;
arr[ 933 ]= 321 ;
arr[ 934 ]= 641 ;
arr[ 935 ]= 933 ;
arr[ 936 ]= 55 ;
arr[ 937 ]= 793 ;
arr[ 938 ]= 31 ;
arr[ 939 ]= 410 ;
arr[ 940 ]= 636 ;
arr[ 941 ]= 948 ;
arr[ 942 ]= 767 ;
arr[ 943 ]= 169 ;
arr[ 944 ]= 405 ;
arr[ 945 ]= 594 ;
arr[ 946 ]= 559 ;
arr[ 947 ]= 439 ;
arr[ 948 ]= 732 ;
arr[ 949 ]= 17 ;
arr[ 950 ]= 640 ;
arr[ 951 ]= 841 ;
arr[ 952 ]= 392 ;
arr[ 953 ]= 495 ;
arr[ 954 ]= 488 ;
arr[ 955 ]= 431 ;
arr[ 956 ]= 445 ;
arr[ 957 ]= 598 ;
arr[ 958 ]= 191 ;
arr[ 959 ]= 880 ;
arr[ 960 ]= 49 ;
arr[ 961 ]= 302 ;
arr[ 962 ]= 479 ;
arr[ 963 ]= 0 ;
arr[ 964 ]= 901 ;
arr[ 965 ]= 738 ;
arr[ 966 ]= 484 ;
arr[ 967 ]= 103 ;
arr[ 968 ]= 761 ;
arr[ 969 ]= 576 ;
arr[ 970 ]= 573 ;
arr[ 971 ]= 246 ;
arr[ 972 ]= 963 ;
arr[ 973 ]= 953 ;
arr[ 974 ]= 150 ;
arr[ 975 ]= 45 ;
arr[ 976 ]= 523 ;
arr[ 977 ]= 614 ;
arr[ 978 ]= 581 ;
arr[ 979 ]= 825 ;
arr[ 980 ]= 48 ;
arr[ 981 ]= 951 ;
arr[ 982 ]= 347 ;
arr[ 983 ]= 613 ;
arr[ 984 ]= 774 ;
arr[ 985 ]= 865 ;
arr[ 986 ]= 602 ;
arr[ 987 ]= 125 ;
arr[ 988 ]= 607 ;
arr[ 989 ]= 354 ;
arr[ 990 ]= 241 ;
arr[ 991 ]= 849 ;
arr[ 992 ]= 569 ;
arr[ 993 ]= 56 ;
arr[ 994 ]= 218 ;
arr[ 995 ]= 487 ;
arr[ 996 ]= 81 ;
arr[ 997 ]= 388 ;
arr[ 998 ]= 890 ;
arr[ 999 ]= 924 ;
 }