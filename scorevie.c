void GestScoreVie(hero *h, int collision_type)
{
    switch(collision_type)
    {
    	case 0 :
        {
             h->score =  h->score+100;
             printf("%d   ",h->score);
            break;
        }
        case 2 :
        {
            h->vie++;
            break;
        }
        case 3 :
        {
            h->vie--;
            printf("%d   ",h->vie);
            break;
        }
        default : break;
    }
}
