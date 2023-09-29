<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Order extends Model
{
    use HasFactory;

    protected $table = 'orders';

    protected $primaryKey = 'id';

    protected $fillable = [
        'type',
        'status',
        'price',
        'client_id',
        'boat_id'
    ];

    public function client()
    {
        return $this->belongsTo('App\Models\Client');
    }

    public function boats()
    {
        return $this->hasOne('App\Models\Boat');
    }
}
