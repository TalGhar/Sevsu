<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('clients', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name', 35);
            $table->string('surname', 35);
            $table->string('patron', 35);
            $table->string('email')->unique();
            $table->string('password');
            $table->timestamps();
        });
        Schema::create('boats', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name', 35);
            $table->text('description');
            $table->integer('owner_id')->unsigned();
            $table->foreign('owner_id')->references('id')->on('clients');
            $table->integer('rented_id')->nullable();
            $table->decimal('price', 10, 2);
            $table->string('status', 20);
            $table->date('rented_from')->nullable();
            $table->date('rented_to')->nullable();
            $table->timestamps();
        });
        Schema::create('boats_images', function (Blueprint $table) {
            $table->increments('id');
            $table->integer('boat_id')->unsigned();
            $table->foreign('boat_id')->references('id')->on('boats');
            $table->string('filename');
            $table->timestamps();
        });

        Schema::create('awards', function (Blueprint $table) {
            $table->increments('id');
            $table->string('award_title');
            $table->string('award_text');
            $table->string('award_image');
        });

        Schema::create('news', function (Blueprint $table) {
            $table->increments('id');
            $table->string('news_title');
            $table->string('news_text');
            $table->string('news_image');
            $table->timestamps();
        });

        Schema::create('history', function (Blueprint $table) {
            $table->increments('id');
            $table->text('history_text');
        });

    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::table('boats', function (Blueprint $table) {
            $table->dropForeign('owner_id');
            $table->dropForeign('rented_id');
            $table->dropForeign('client_id');
        });
        Schema::table('boats_images', function (Blueprint $table) {
            $table->dropForeign('boat_id');
        });
        Schema::table('orders', function (Blueprint $table) {
            $table->dropForeign('client_id');
        });

        Schema::dropIfExists('awards');
        Schema::dropIfExists('boats');
        Schema::dropIfExists('boats_images');
        Schema::dropIfExists('owners');
        Schema::dropIfExists('clients');
        Schema::dropIfExists('orders');
    }
};
