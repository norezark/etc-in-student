class Rectangle
{
    int top, left, width, height;
    enum OverlapState
    {
        IN, OUT, OVERLAP
    };
    Rectangle(int top, int left, int width, int height)
    {
        if(top < 0) top = 0;
        if(left < 0) left = 0;
        if(width < 1) width = 1;
        if(height < 1) height = 1;
        this.top = top;
        this.left = left;
        this.width = width;
        this.height = height;
    }

    OverlapState checkOverlap(Rectangle r)
    {
        if(this.top < r.top
            && (r.top+r.height) < (this.top+this.height)
            && this.left < r.left
            && (r.left+r.width) < (this.left+this.width))
        {
            return OverlapState.IN;
        }
        else if((r.top+r.height < this.top
                    || this.top+this.height < r.top)
                && (r.left+r.width < this.left
                    || this.left+this.width < r.left))
        {
            return OverlapState.OUT;
        }

        return OverlapState.OVERLAP;
    }
}
