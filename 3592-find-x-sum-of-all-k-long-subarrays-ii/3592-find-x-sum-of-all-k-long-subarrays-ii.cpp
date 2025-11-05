#define ll long long

class comp1{
public:
    //{least frequent, smaller number}
    bool operator()(auto &a,auto &b) const{
        if(a.first==b.first) return a.second<b.second;

        return a.first<b.first;
    }
};

class comp2{
public:
    // {most frequent,bigger number}
    bool operator()(auto &a,auto &b) const{
        if(a.first==b.first) return a.second>b.second;

        return a.first>b.first;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        //map to keep frequency of each element
        unordered_map<int ,ll>mp;
        //sum to keep final sum after each window
        ll sum=0;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        int i=0;
        vector<ll>ans;
        set<pair<ll,int>,comp1>s1;//up->most likely to get out from here
        set<pair<ll,int>,comp2>s2,s;//up->most likely to come in s1

        for(auto &val: mp)
        {
            s.insert({val.second,val.first});
        }
        int cnt=0;
        //tranfer element belonging to appropriate set s1 or s2
        while(!s.empty())
        {
            auto [c,v]=*s.begin();
            s.erase(s.begin());
            if(cnt<x)
            {
                s1.insert({c,v});
                sum+=c*v;
            }
            else
            {
                s2.insert({c,v});
            }
            cnt++;
        }
        ans.push_back(sum);
        //window from i to j
        //NOTE: whenever s1 is update sum will also be updated
        for(int j=k;j<n;j++)
        {
            //now remove all cases because of number nums[i]
            if(s1.find({mp[nums[i]],nums[i]})==s1.end())
            {
                //found in s2
                auto it=s2.find({mp[nums[i]],nums[i]});
                // it->first--;
                if(it!=s2.end())
                {
                    s2.erase(it);
                }
                s2.insert({mp[nums[i]]-1,nums[i]});
                mp[nums[i]]--;
            }
            else
            {
                //found in s1
                auto it=s1.find({mp[nums[i]],nums[i]});
                // *it->first--;
                if(it!=s1.end())s1.erase(it);
                s1.insert({mp[nums[i]]-1,nums[i]});
                mp[nums[i]]--;
                sum-=nums[i];
            }
            i++;
            //now remove all cases because of nums[j]
            if(s1.find({mp[nums[j]],nums[j]})==s1.end())
            {
                //found in s2
                auto it=s2.find({mp[nums[j]],nums[j]});
                // *it->first++;
                if(it!=s2.end())s2.erase(it);
                s2.insert({mp[nums[j]]+1,nums[j]});
                mp[nums[j]]++;
            }
            else
            {
                //found in s1
                auto it=s1.find({mp[nums[j]],nums[j]});
                // *it->first++;
                if(it!=s1.end())s1.erase(it);
                s1.insert({mp[nums[j]]+1,nums[j]});
                mp[nums[j]]++;
                sum+=nums[j];
            }
            //make size of set s1 to x if possible
            while(s1.size()<x && s2.size()>0)
            {
                auto v2=*s2.begin();
                s2.erase(s2.begin());
                s1.insert(v2);
                sum+=v2.first*v2.second;
            }
            //now swap the positions of top of s1 and top of s2 if:
            // 1-> top frequency count of s1 < top frequency count of s2
            // 2-> if frequency equal and s1 element value < s2 element value
            while(s2.size()>0)
            {
                auto v1=*s1.begin();
                auto v2=*s2.begin();
                if(v1.first<v2.first || (v1.first==v2.first && v1.second<v2.second))
                {
                    sum-=v1.first*v1.second;
                    sum+=v2.first*v2.second;
                    s1.erase(s1.begin());
                    s2.erase(s2.begin());
                    s1.insert({v2.first,v2.second});
                    s2.insert({v1.first,v1.second});
                }
                else break;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};