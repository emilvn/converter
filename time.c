

float minutes_to_weeks(float minutes)
{
    return minutes / 10080;
}

float weeks_to_minutes(float weeks)
{
    return weeks * 10080;
}

float weeks_to_years(float weeks)
{
    return weeks / 52;
}

float years_to_weeks(float years)
{
    return years * 52;
}

float years_to_minutes(float years)
{
    return weeks_to_minutes(years_to_weeks(years));
}   

float minutes_to_years(float minutes)
{
    return weeks_to_years(minutes_to_weeks(minutes));
}

float get_time_conversion(char from, char to, float value)
{
    switch (from)
    {
    case 'm':
        if(to == 'w'){
            return minutes_to_weeks(value);
        } else if(to == 'y'){
            return minutes_to_years(value);
        }
        break;
    case 'w':
        if(to == 'm'){
            return weeks_to_minutes(value);
        } else if(to == 'y'){
            return weeks_to_years(value);
        }
        break;
    case 'y':
        if(to == 'w'){
            return years_to_weeks(value);
        } else if(to == 'm'){
            return years_to_minutes(value);
        }
        break;
    default:
        break;
    }
    return 0.0;
}