<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class OrderBoat extends Model
{
    use HasFactory;

    protected $table = 'orders_boats';

    public function order()
    {
        return $this->belongsTo('App\Models\Order');
    }

    public function boat()
    {
        return $this->belongsTo('App\Models\Boat');
    }
}
