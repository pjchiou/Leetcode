#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
  vector<int> v1,v2;

  v1.push_back(1);
  //v1.push_back(2);

  //v2.push_back(3);
  //v2.push_back(4);

  cout << findMedianSortedArrays(v1,v2) << endl;

  return(0);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int iIndex=(nums1.size()+nums2.size())/2;
    int iCount=1;
    vector<int> temp;

    if( (nums1.size()+nums2.size())%2==0 )
    {
      iCount=2;
      iIndex--;
    }

    if( (nums1.size()+nums2.size())==1 )
    {
      return( nums1.empty()?nums2.front():nums1.front() );
    }

    if( (nums1.size()+nums2.size())==2)
    {
      double dSum=0.0;

      for(int i=0;i<nums1.size();i++)
        dSum += nums1.at(i);

      for(int i=0;i<nums2.size();i++)
        dSum += nums2.at(i);

      return(dSum/2.0);

    }

    while( !nums1.empty() || !nums2.empty() )
    {
      int iN1,iN2;

      if( !nums1.empty() && !nums2.empty() )
      {
        iN1 = nums1.back();
        iN2 = nums2.back();

        if(iN1>=iN2)
          nums1.pop_back();
        else
          nums2.pop_back();
      }
      else if( !nums1.empty() )
        nums1.pop_back();
      else
        nums2.pop_back();

      iIndex--;

      if( iIndex==0 )
      {
        while(iCount>0)
        {
          if( !nums1.empty() && !nums2.empty() )
          {
            if(nums1.back()>=nums2.back())
            {
              temp.push_back(nums1.back());
              nums1.pop_back();
            }
            else
            {
              temp.push_back(nums2.back());
              nums2.pop_back();
            }
          }
          else if( !nums1.empty() )
          {
            temp.push_back(nums1.back());
            nums1.pop_back();
          }
          else
          {
            temp.push_back(nums2.back());
            nums2.pop_back();
          }

          iCount--;
        }

        break;
      }

    }

    if(temp.size()==2)
      return( ((double)temp.front()+temp.back())/2.0 );
    else
      return((double)temp.front());

}
