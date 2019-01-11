pair<int,int> hd(node* nn)//height and diameter
{
    if(nn == NULL)
    return {0,0};//{h,d}
    pair<int,int>ans;
    pair<int,int>left_data = hd(nn->l);
    pair<int,int>right_data = hd(nn->r);
    int lh,rh,ld,rd,height,diameter;
    lh = left_data.X;
    rh = right_data.X;
    ld = left_data.Y;
    rd = right_data.Y;
    height = 1 + max(lh,rh);
    diameter = max( lh+rh , max(ld,rd) );
    return {height,diameter};
}
