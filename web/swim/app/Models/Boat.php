<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Boat extends Model
{
    use HasFactory;

    protected $table = 'boats';

    protected $primaryKey = 'id';

    protected $fillable = [
        'name',
        'description',
        'price',
        'status'
    ];

    public function owner()
    {
        return $this->belongsTo('App\Models\Owner');
    }

    public function orders()
    {
        return $this->belongsToMany('App\Models\Order');
    }

    public function images()
    {
        return $this->hasMany('App\Models\BoatImage');
    }
}
